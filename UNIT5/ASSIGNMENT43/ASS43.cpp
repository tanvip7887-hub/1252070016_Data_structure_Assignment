/*Write a Program to implement Kruskal’s algorithm to find the minimum spanning tree of a user defined graph. Use Adjacency List to represent 
a graph.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge_TRP {
    int u_TRP;
    int v_TRP;
    int weight_TRP;
};

struct DisjointSet_TRP {
    vector<int> parent_TRP;
    vector<int> rank_TRP;

    DisjointSet_TRP(int n_TRP) {
        parent_TRP.resize(n_TRP);
        rank_TRP.resize(n_TRP, 0);
        for(int i_TRP = 0; i_TRP < n_TRP; i_TRP++) {
            parent_TRP[i_TRP] = i_TRP;
        }
    }

    int find_TRP(int x_TRP) {
        if(parent_TRP[x_TRP] != x_TRP) {
            parent_TRP[x_TRP] = find_TRP(parent_TRP[x_TRP]);
        }
        return parent_TRP[x_TRP];
    }

    void unite_TRP(int x_TRP, int y_TRP) {
        int xroot_TRP = find_TRP(x_TRP);
        int yroot_TRP = find_TRP(y_TRP);

        if(rank_TRP[xroot_TRP] < rank_TRP[yroot_TRP]) {
            parent_TRP[xroot_TRP] = yroot_TRP;
        } else if(rank_TRP[xroot_TRP] > rank_TRP[yroot_TRP]) {
            parent_TRP[yroot_TRP] = xroot_TRP;
        } else {
            parent_TRP[yroot_TRP] = xroot_TRP;
            rank_TRP[xroot_TRP]++;
        }
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
    int n_TRP, e_TRP;
    cout << "Enter number of vertices: ";
    cin >> n_TRP;
    cout << "Enter number of edges: ";
    cin >> e_TRP;

    vector<Edge_TRP> edges_TRP(e_TRP);
    for(int i_TRP = 0; i_TRP < e_TRP; i_TRP++) {
        cout << "Enter edge (u v weight): ";
        cin >> edges_TRP[i_TRP].u_TRP >> edges_TRP[i_TRP].v_TRP >> edges_TRP[i_TRP].weight_TRP;
    }

    kruskalMST_TRP(edges_TRP, n_TRP);

    return 0;
}
