/*Write a Program to implement Prim’s algorithm to find minimum spanning tree of a user defined graph. Use Adjacency List to represent a graph.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge_TRP 
{
    int vertex_TRP;
    int weight_TRP;
};

struct Compare_TRP 
{
    bool operator()(pair<int,int> a_TRP, pair<int,int> b_TRP) 
    {
        return a_TRP.second > b_TRP.second;
    }
};

void primMST_TRP(vector<vector<Edge_TRP>> &adj_TRP, int n_TRP) 
{
    vector<int> key_TRP(n_TRP, INT_MAX);
    vector<int> parent_TRP(n_TRP, -1);
    vector<bool> inMST_TRP(n_TRP, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare_TRP> pq_TRP;
    key_TRP[0] = 0;
    pq_TRP.push({0,0});

    while(!pq_TRP.empty()) 
    {
        int u_TRP = pq_TRP.top().first;
        pq_TRP.pop();
        inMST_TRP[u_TRP] = true;

        for(auto &edge_TRP : adj_TRP[u_TRP]) 
        {
            int v_TRP = edge_TRP.vertex_TRP;
            int w_TRP = edge_TRP.weight_TRP;
            if(!inMST_TRP[v_TRP] && w_TRP < key_TRP[v_TRP]) 
            {
                key_TRP[v_TRP] = w_TRP;
                pq_TRP.push({v_TRP, key_TRP[v_TRP]});
                parent_TRP[v_TRP] = u_TRP;
            }
        }
    }

    cout << "Edges in MST:\n";
    int totalWeight_TRP = 0;
    for(int i_TRP=1; i_TRP<n_TRP; i_TRP++) 
    {
        cout << parent_TRP[i_TRP] << " - " << i_TRP << " (Weight: " << key_TRP[i_TRP] << ")\n";
        totalWeight_TRP += key_TRP[i_TRP];
    }
    cout << "Total weight of MST: " << totalWeight_TRP << endl;
}

int main() 
{
    int n_TRP, e_TRP;
    cout << "Enter number of vertices: ";
    cin >> n_TRP;
    cout << "Enter number of edges: ";
    cin >> e_TRP;

    vector<vector<Edge_TRP>> adj_TRP(n_TRP);
    
    for(int i_TRP=0; i_TRP<e_TRP; i_TRP++) 
    {
        int u_TRP, v_TRP, w_TRP;
        cout << "Enter edge (u v weight): ";
        cin >> u_TRP >> v_TRP >> w_TRP;
        adj_TRP[u_TRP].push_back({v_TRP, w_TRP});
        adj_TRP[v_TRP].push_back({u_TRP, w_TRP}); // Comment this line for directed graph
    }

    primMST_TRP(adj_TRP, n_TRP);

    return 0;
}
