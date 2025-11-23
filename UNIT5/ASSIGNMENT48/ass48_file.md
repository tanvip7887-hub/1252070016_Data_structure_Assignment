
ASSIGNMENT 48
==============

AIM - Write a Program to implement Prim’s algorithm to find minimum spanning tree of a user defined graph. Use Adjacency List to represent a graph.

THEORY
-------

Graph Representation (Adjacency List):
    Each vertex stores a list of edges connecting it to neighboring vertices with corresponding weights.
    Efficient for sparse graphs.

Prim’s Algorithm:
    Finds the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph.

Steps:
    Start from any vertex and mark it as part of MST.
    Select the minimum weight edge connecting a vertex in MST to a vertex outside MST.
    Include the selected edge and vertex in MST.
    Repeat until all vertices are included in MST.


PROGRAM
--------

```CPP

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

```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS48.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter number of vertices: 5
Enter number of edges: 7
Enter edge (u v weight): 0 1 2
Enter edge (u v weight): 0 3 6
Enter edge (u v weight): 1 2 3
Enter edge (u v weight): 1 3 8
Enter edge (u v weight): 1 4 5
Enter edge (u v weight): 2 4 7
Enter edge (u v weight): 3 4 9
Edges in MST:
0 - 1 (Weight: 2)
1 - 2 (Weight: 3)
1 - 4 (Weight: 5)
0 - 3 (Weight: 6)
Total weight of MST: 16
