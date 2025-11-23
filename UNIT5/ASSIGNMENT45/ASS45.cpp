/*Write a Program to accept a graph from a user and represent it with Adjacency List and perform BFS and DFS traversals on it.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS_TRP(vector<vector<int>> &adj_TRP, int start_TRP) {
    int n_TRP = adj_TRP.size();
    vector<bool> visited_TRP(n_TRP, false);
    queue<int> q_TRP;

    visited_TRP[start_TRP] = true;
    q_TRP.push(start_TRP);

    cout << "BFS Traversal: ";
    while(!q_TRP.empty()) {
        int node_TRP = q_TRP.front();
        q_TRP.pop();
        cout << node_TRP << " ";

        for(int neighbor_TRP : adj_TRP[node_TRP]) {
            if(!visited_TRP[neighbor_TRP]) {
                visited_TRP[neighbor_TRP] = true;
                q_TRP.push(neighbor_TRP);
            }
        }
    }
    cout << endl;
}

void DFSUtil_TRP(vector<vector<int>> &adj_TRP, int node_TRP, vector<bool> &visited_TRP) {
    visited_TRP[node_TRP] = true;
    cout << node_TRP << " ";

    for(int neighbor_TRP : adj_TRP[node_TRP]) {
        if(!visited_TRP[neighbor_TRP]) {
            DFSUtil_TRP(adj_TRP, neighbor_TRP, visited_TRP);
        }
    }
}

void DFS_TRP(vector<vector<int>> &adj_TRP, int start_TRP) {
    int n_TRP = adj_TRP.size();
    vector<bool> visited_TRP(n_TRP, false);

    cout << "DFS Traversal: ";
    DFSUtil_TRP(adj_TRP, start_TRP, visited_TRP);
    cout << endl;
}

int main() {
    int n_TRP, e_TRP;
    cout << "Enter number of vertices: ";
    cin >> n_TRP;
    cout << "Enter number of edges: ";
    cin >> e_TRP;

    vector<vector<int>> adj_TRP(n_TRP);

    for(int i_TRP = 0; i_TRP < e_TRP; i_TRP++) {
        int u_TRP, v_TRP;
        cout << "Enter edge (u v): ";
        cin >> u_TRP >> v_TRP;
        adj_TRP[u_TRP].push_back(v_TRP);
        adj_TRP[v_TRP].push_back(u_TRP); // Comment this line for directed graph
    }

    int start_TRP;
    cout << "Enter starting vertex for BFS and DFS: ";
    cin >> start_TRP;

    BFS_TRP(adj_TRP, start_TRP);
    DFS_TRP(adj_TRP, start_TRP);

    return 0;
}
