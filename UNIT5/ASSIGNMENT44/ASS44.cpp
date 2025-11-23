/*Write a Program to implement Dijkstra’s algorithm to find shortest distance between two nodes of a user defined graph. Use Adjacency List 
to represent a graph. */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge_TRP {
    int vertex_TRP;
    int weight_TRP;
};

void dijkstra_TRP(vector<vector<Edge_TRP>> &adj_TRP, int n_TRP, int start_TRP, int end_TRP) {
    vector<int> dist_TRP(n_TRP, INT_MAX);
    vector<int> parent_TRP(n_TRP, -1);
    vector<bool> visited_TRP(n_TRP, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq_TRP;

    dist_TRP[start_TRP] = 0;
    pq_TRP.push({0, start_TRP});

    while(!pq_TRP.empty()) {
        int u_TRP = pq_TRP.top().second;
        pq_TRP.pop();

        if(visited_TRP[u_TRP]) continue;
        visited_TRP[u_TRP] = true;

        for(auto &e_TRP : adj_TRP[u_TRP]) {
            int v_TRP = e_TRP.vertex_TRP;
            int w_TRP = e_TRP.weight_TRP;
            if(dist_TRP[u_TRP] + w_TRP < dist_TRP[v_TRP]) {
                dist_TRP[v_TRP] = dist_TRP[u_TRP] + w_TRP;
                parent_TRP[v_TRP] = u_TRP;
                pq_TRP.push({dist_TRP[v_TRP], v_TRP});
            }
        }
    }

    if(dist_TRP[end_TRP] == INT_MAX) {
        cout << "No path exists between " << start_TRP << " and " << end_TRP << ".\n";
        return;
    }

    cout << "Shortest distance from " << start_TRP << " to " << end_TRP << " is " << dist_TRP[end_TRP] << endl;
    cout << "Path: ";
    vector<int> path_TRP;
    for(int v_TRP = end_TRP; v_TRP != -1; v_TRP = parent_TRP[v_TRP]) {
        path_TRP.push_back(v_TRP);
    }
    for(int i_TRP = path_TRP.size()-1; i_TRP >= 0; i_TRP--) {
        cout << path_TRP[i_TRP] << " ";
    }
    cout << endl;
}

int main() {
    int n_TRP, e_TRP;
    cout << "Enter number of vertices: ";
    cin >> n_TRP;
    cout << "Enter number of edges: ";
    cin >> e_TRP;

    vector<vector<Edge_TRP>> adj_TRP(n_TRP);
    for(int i_TRP = 0; i_TRP < e_TRP; i_TRP++) {
        int u_TRP, v_TRP, w_TRP;
        cout << "Enter edge (u v weight): ";
        cin >> u_TRP >> v_TRP >> w_TRP;
        adj_TRP[u_TRP].push_back({v_TRP, w_TRP});
        adj_TRP[v_TRP].push_back({u_TRP, w_TRP}); // comment this line if graph is directed
    }

    int start_TRP, end_TRP;
    cout << "Enter start node: ";
    cin >> start_TRP;
    cout << "Enter end node: ";
    cin >> end_TRP;

    dijkstra_TRP(adj_TRP, n_TRP, start_TRP, end_TRP);

    return 0;
}
