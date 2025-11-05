#include <iostream>
#include <climits>
using namespace std;

const int V = 5;

class Prim {
private:
    int graph[V][V];
    
public:
    Prim() {
        // Initialize graph with weights
        int temp[V][V] = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };
        
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                graph[i][j] = temp[i][j];
    }
    
    void primMST() {
        int parent[V];      // Store MST
        int key[V];         // Key values
        bool mstSet[V];     // Track vertices in MST
        
        // Initialize all keys as INFINITE
        for(int i = 0; i < V; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
        
        // Start with first vertex
        key[0] = 0;
        parent[0] = -1;
        
        // The MST will have V vertices
        for(int count = 0; count < V-1; count++) {
            // Pick minimum key vertex not yet in MST
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            
            // Update key values of adjacent vertices
            for(int v = 0; v < V; v++) {
                if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
        
        printMST(parent);
    }
    
private:
    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX, min_index;
        
        for(int v = 0; v < V; v++) {
            if(!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }
    
    void printMST(int parent[]) {
        cout << "Prim's MST:" << endl;
        cout << "Edge \tWeight" << endl;
        int totalWeight = 0;
        for(int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
            totalWeight += graph[i][parent[i]];
        }
        cout << "Total weight: " << totalWeight << endl;
    }
};

int main() {
    Prim p;
    p.primMST();
    return 0;
}
