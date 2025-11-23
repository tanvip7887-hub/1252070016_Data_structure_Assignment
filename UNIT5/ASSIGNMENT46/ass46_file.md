
ASSIGNMENT 46
==============

AIM - Write a Program to implement Kruskal’s algorithm to find the minimum spanning tree of a user defined graph. Use Adjacency Matrix to represent a graph.


THEORY 
-------

Graph Representation (Adjacency Matrix):
    A 2D matrix where matrix[i][j] stores the weight of the edge between vertex i and j.
    0 indicates no edge.
    Suitable for dense graphs.

Kruskal’s Algorithm:
    Finds the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph.

Steps:
    List all edges with weights.
    Sort edges in ascending order of weight.
    Pick edges one by one and add to MST if they don’t form a cycle.
    Use Disjoint Set (Union-Find) to detect cycles.
    Repeat until MST has V-1 edges (V = number of vertices).


PROGRAM
--------

```CPP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge_TRP {
    int u_TRP, v_TRP, weight_TRP;
};

struct DisjointSet_TRP {
    vector<int> parent_TRP, rank_TRP;
    DisjointSet_TRP(int n_TRP) {
        parent_TRP.resize(n_TRP);
        rank_TRP.resize(n_TRP, 0);
        for(int i_TRP=0;i_TRP<n_TRP;i_TRP++) parent_TRP[i_TRP]=i_TRP;
    }
    int find_TRP(int x_TRP) {
        if(parent_TRP[x_TRP]!=x_TRP) parent_TRP[x_TRP]=find_TRP(parent_TRP[x_TRP]);
        return parent_TRP[x_TRP];
    }
    void unite_TRP(int x_TRP, int y_TRP) {
        int xroot_TRP = find_TRP(x_TRP);
        int yroot_TRP = find_TRP(y_TRP);
        if(rank_TRP[xroot_TRP]<rank_TRP[yroot_TRP]) parent_TRP[xroot_TRP]=yroot_TRP;
        else if(rank_TRP[xroot_TRP]>rank_TRP[yroot_TRP]) parent_TRP[yroot_TRP]=xroot_TRP;
        else { parent_TRP[yroot_TRP]=xroot_TRP; rank_TRP[xroot_TRP]++; }
    }
};

bool compareEdges_TRP(Edge_TRP a_TRP, Edge_TRP b_TRP) {
    return a_TRP.weight_TRP < b_TRP.weight_TRP;
}

void kruskalMST_TRP(vector<Edge_TRP> &edges_TRP, int n_TRP) {
    sort(edges_TRP.begin(), edges_TRP.end(), compareEdges_TRP);
    DisjointSet_TRP ds_TRP(n_TRP);
    cout << "Edges in MST:\n";
    int mstWeight_TRP = 0;
    for(auto e_TRP : edges_TRP) {
        int uSet_TRP = ds_TRP.find_TRP(e_TRP.u_TRP);
        int vSet_TRP = ds_TRP.find_TRP(e_TRP.v_TRP);
        if(uSet_TRP != vSet_TRP) {
            cout << e_TRP.u_TRP << " - " << e_TRP.v_TRP << " (Weight: " << e_TRP.weight_TRP << ")\n";
            mstWeight_TRP += e_TRP.weight_TRP;
            ds_TRP.unite_TRP(uSet_TRP, vSet_TRP);
        }
    }
    cout << "Total weight of MST: " << mstWeight_TRP << endl;
}

int main() {
    int n_TRP;
    cout << "Enter number of vertices: ";
    cin >> n_TRP;

    vector<vector<int>> adj_TRP(n_TRP, vector<int>(n_TRP));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for(int i_TRP=0;i_TRP<n_TRP;i_TRP++) {
        for(int j_TRP=0;j_TRP<n_TRP;j_TRP++)
            cin >> adj_TRP[i_TRP][j_TRP];
    }

    vector<Edge_TRP> edges_TRP;
    for(int i_TRP=0;i_TRP<n_TRP;i_TRP++) {
        for(int j_TRP=i_TRP+1;j_TRP<n_TRP;j_TRP++) {
            if(adj_TRP[i_TRP][j_TRP] != 0) {
                edges_TRP.push_back({i_TRP, j_TRP, adj_TRP[i_TRP][j_TRP]});
            }
        }
    }

    kruskalMST_TRP(edges_TRP, n_TRP);

    return 0;
}

```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS46.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter number of vertices: 4
Enter adjacency matrix (0 if no edge):
0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0

Edges in MST:
2 - 3 (Weight: 4)
0 - 3 (Weight: 5)
0 - 2 (Weight: 6)
Total weight of MST: 15
