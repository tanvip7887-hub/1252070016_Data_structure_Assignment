/*Write a Program to implement Dijkstra’s algorithm to find shortest distance between two nodes of a user defined graph. Use Adjacency 
List to represent a graph.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge_TRP
{
    int vertex_TRP;
    int weight_TRP;
};

int minDistance_TRP(vector<int> &dist_TRP, vector<bool> &visited_TRP, int n_TRP) 
{
    int minVal_TRP = INT_MAX, minIndex_TRP = -1;
    for(int i=0;i<n_TRP;i++) 
    {
        if(!visited_TRP[i] && dist_TRP[i] <= minVal_TRP) 
        {
            minVal_TRP = dist_TRP[i];
            minIndex_TRP = i;
        }
    }
    return minIndex_TRP;
}

void dijkstra_TRP(vector<vector<Edge_TRP>> &adj_TRP, int start_TRP, int end_TRP) 
{
    int n_TRP = adj_TRP.size();
    vector<int> dist_TRP(n_TRP, INT_MAX);
    vector<int> parent_TRP(n_TRP, -1);
    vector<bool> visited_TRP(n_TRP, false);

    dist_TRP[start_TRP] = 0;

    for(int count_TRP=0; count_TRP<n_TRP-1; count_TRP++) 
    {
        int u_TRP = minDistance_TRP(dist_TRP, visited_TRP, n_TRP);
        if(u_TRP == -1) break; 
        visited_TRP[u_TRP] = true;

        for(auto edge_TRP : adj_TRP[u_TRP]) 
        {
            int v_TRP = edge_TRP.vertex_TRP;
            int w_TRP = edge_TRP.weight_TRP;
            if(!visited_TRP[v_TRP] && dist_TRP[u_TRP] + w_TRP < dist_TRP[v_TRP]) {
                dist_TRP[v_TRP] = dist_TRP[u_TRP] + w_TRP;
                parent_TRP[v_TRP] = u_TRP;
            }
        }
    }

    if(dist_TRP[end_TRP] == INT_MAX) 
    {
        cout << "No path exists between " << start_TRP << " and " << end_TRP << ".\n";
        return;
    }

    cout << "Shortest distance from " << start_TRP << " to " << end_TRP << " is " << dist_TRP[end_TRP] << endl;
    cout << "Path: ";
    vector<int> path_TRP;
    for(int v_TRP = end_TRP; v_TRP != -1; v_TRP = parent_TRP[v_TRP])
        path_TRP.push_back(v_TRP);
    for(int i=path_TRP.size()-1;i>=0;i--) cout << path_TRP[i] << " ";
    cout << endl;
}


int main() 
{
    int n_TRP, e_TRP;
    cout << "Enter number of vertices: ";
    cin >> n_TRP;
    cout << "Enter number of edges: ";
    cin >> e_TRP;

    vector<vector<Edge_TRP>> adj_TRP(n_TRP);

    for(int i=0;i<e_TRP;i++) 
    {
        int u_TRP, v_TRP, w_TRP;
        cout << "Enter edge (u v weight): ";
        cin >> u_TRP >> v_TRP >> w_TRP;
        adj_TRP[u_TRP].push_back({v_TRP, w_TRP});
        adj_TRP[v_TRP].push_back({u_TRP, w_TRP}); // Comment for directed graph
    }

    int start_TRP, end_TRP;
    cout << "Enter start node: ";
    cin >> start_TRP;
    cout << "Enter end node: ";
    cin >> end_TRP;

    dijkstra_TRP(adj_TRP, start_TRP, end_TRP);

    return 0;
}
