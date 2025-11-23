
ASSIGNMENT 41
==============

AIM - Write a Program to accept a graph from a user and represent it with Adjacency Matrix and perform BFS and DFS traversals on it.


THEORY
-------

A graph is a collection of vertices (nodes) and edges (connections).

Adjacency Matrix:
    A 2D array representation of a graph.
    matrix[i][j] = 1 if there is an edge between vertex i and j; otherwise 0.
    Suitable for dense graphs.

Breadth-First Search (BFS):
    Explores nodes level by level starting from a given node.
    Uses a queue to keep track of nodes to visit.
    Efficient for finding shortest paths in unweighted graphs.

Depth-First Search (DFS):
    Explores nodes deeply along a branch before backtracking.
    Uses recursion or a stack.
    Useful for cycle detection, topological sorting, and connectivity checks.



PROGRAM
---------

```CPP

#include <iostream>
#include <queue>
using namespace std;

void BFS_TRP(int adjMatrix_TRP[][20], int n_TRP, int start_TRP) {
    bool visited_TRP[20] = {false};
    queue<int> q_TRP;
    visited_TRP[start_TRP] = true;
    q_TRP.push(start_TRP);
    cout << "BFS Traversal: ";
    while(!q_TRP.empty()) {
        int node_TRP = q_TRP.front();
        q_TRP.pop();
        cout << node_TRP << " ";
        for(int i_TRP = 0; i_TRP < n_TRP; i_TRP++) {
            if(adjMatrix_TRP[node_TRP][i_TRP] && !visited_TRP[i_TRP]) {
                visited_TRP[i_TRP] = true;
                q_TRP.push(i_TRP);
            }
        }
    }
    cout << endl;
}

void DFSUtil_TRP(int adjMatrix_TRP[][20], int n_TRP, int start_TRP, bool visited_TRP[]) {
    visited_TRP[start_TRP] = true;
    cout << start_TRP << " ";
    for(int i_TRP = 0; i_TRP < n_TRP; i_TRP++) {
        if(adjMatrix_TRP[start_TRP][i_TRP] && !visited_TRP[i_TRP])
            DFSUtil_TRP(adjMatrix_TRP, n_TRP, i_TRP, visited_TRP);
    }
}

void DFS_TRP(int adjMatrix_TRP[][20], int n_TRP, int start_TRP) {
    bool visited_TRP[20] = {false};
    cout << "DFS Traversal: ";
    DFSUtil_TRP(adjMatrix_TRP, n_TRP, start_TRP, visited_TRP);
    cout << endl;
}

int main() {
    int n_TRP, e_TRP, u_TRP, v_TRP;
    int adjMatrix_TRP[20][20] = {0};
    
    cout << "Enter number of vertices: ";
    cin >> n_TRP;
    cout << "Enter number of edges: ";
    cin >> e_TRP;

    for(int i_TRP = 0; i_TRP < e_TRP; i_TRP++) {
        cout << "Enter edge (u v): ";
        cin >> u_TRP >> v_TRP;
        adjMatrix_TRP[u_TRP][v_TRP] = 1;
        adjMatrix_TRP[v_TRP][u_TRP] = 1; // For undirected graph
    }

    cout << "\nAdjacency Matrix:\n";
    for(int i_TRP = 0; i_TRP < n_TRP; i_TRP++) {
        for(int j_TRP = 0; j_TRP < n_TRP; j_TRP++)
            cout << adjMatrix_TRP[i_TRP][j_TRP] << " ";
        cout << endl;
    }

    int start_TRP;
    cout << "\nEnter starting vertex for BFS and DFS: ";
    cin >> start_TRP;

    BFS_TRP(adjMatrix_TRP, n_TRP, start_TRP);
    DFS_TRP(adjMatrix_TRP, n_TRP, start_TRP);

    return 0;
}
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS41.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter number of vertices: 5
Enter number of edges: 6
Enter edge (u v): 0 1
Enter edge (u v): 0 2
Enter edge (u v): 1 2
Enter edge (u v): 1 3
Enter edge (u v): 2 4
Enter edge (u v): 3 4

Adjacency Matrix:
0 1 1 0 0
1 0 1 1 0
1 1 0 0 1
0 1 0 0 1
0 0 1 1 0

Enter starting vertex for BFS and DFS: 0
BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 2 4 3
