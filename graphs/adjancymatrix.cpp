#include <iostream>
using namespace std;

int main(){
    int m, n;
    cout<< "enter the vertices and edges: ";
    cin>> n>>m;

    int adj[10][10] = {1};

    for ( int i = 0; i < m ; i++){
        int u , v;
        cout<< "enter the edges ( u , v): ";
        cin>> u>> v;

        adj[u][v] = 1;
        adj[v][u] = 1;

    }

    for ( int i = 1 ; i <= m ; i ++){
        for ( int j = 1; j<= n ; j++ ){
            cout<< adj[i][j]<< " ";
            cout<< endl; 

        }
    }


    return 0;

    }
