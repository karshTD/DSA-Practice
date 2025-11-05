#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// DFS using stack (iterative)
void dfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> st;
    
    st.push(start);
    
    cout << "DFS: ";
    while (!st.empty()) {
        int current = st.top();
        st.pop();
        
        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";
            
            // Push neighbors in reverse order for correct DFS order
            for (int i = graph[current].size() - 1; i >= 0; i--) {
                int neighbor = graph[current][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

// Recursive DFS
void dfsRecursive(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(graph, visited, neighbor);
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},     // Node 0
        {0, 3, 4},  // Node 1
        {0, 5},     // Node 2
        {1},        // Node 3
        {1, 5},     // Node 4
        {2, 4}      // Node 5
    };
    
    dfs(graph, 0);
    
    // Using recursive DFS
    vector<bool> visited(graph.size(), false);
    cout << "DFS Recursive: ";
    dfsRecursive(graph, visited, 0);
    cout << endl;
    
    return 0;
}
