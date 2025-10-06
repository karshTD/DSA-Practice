#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

Node* adj[10];
int n, m;

void addEdge(int u, int v) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = new Node;
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void display() {
    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << " -> ";
        Node* temp = adj[i];
        while (temp != NULL) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    cout << "Enter vertices and edges: ";
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    display();
}
