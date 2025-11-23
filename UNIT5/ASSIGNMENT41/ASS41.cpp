/*Write a Program to accept a graph from a user and represent it with Adjacency Matrix and perform BFS and DFS traversals on it.*/

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
