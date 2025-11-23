/*Write a Program to implement Dijkstra’s algorithm to find shortest distance between two nodes of a user defined graph. Use Adjacency 
Matrix to represent a graph.*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance_TRP(vector<int> &dist_TRP, vector<bool> &visited_TRP, int n_TRP) 
{
    int minVal_TRP = INT_MAX, minIndex_TRP = -1;
    for(int i_TRP=0; i_TRP<n_TRP; i_TRP++) 
    {
        if(!visited_TRP[i_TRP] && dist_TRP[i_TRP] <= minVal_TRP) 
        {
            minVal_TRP = dist_TRP[i_TRP];
            minIndex_TRP = i_TRP;
        }
    }
    return minIndex_TRP;
}

void dijkstra_TRP(vector<vector<int>> &graph_TRP, int start_TRP, int end_TRP) 
{
    int n_TRP = graph_TRP.size();
    vector<int> dist_TRP(n_TRP, INT_MAX);
    vector<int> parent_TRP(n_TRP, -1);
    vector<bool> visited_TRP(n_TRP, false);

    dist_TRP[start_TRP] = 0;

    for(int count_TRP=0; count_TRP<n_TRP-1; count_TRP++) 
    {
        int u_TRP = minDistance_TRP(dist_TRP, visited_TRP, n_TRP);
        if(u_TRP == -1) break;
        visited_TRP[u_TRP] = true;

        for(int v_TRP=0; v_TRP<n_TRP; v_TRP++) 
        {
            if(!visited_TRP[v_TRP] && graph_TRP[u_TRP][v_TRP] != 0 && dist_TRP[u_TRP] + graph_TRP[u_TRP][v_TRP] < dist_TRP[v_TRP]) {
                dist_TRP[v_TRP] = dist_TRP[u_TRP] + graph_TRP[u_TRP][v_TRP];
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
    for(int v_TRP = end_TRP; v_TRP != -1; v_TRP = parent_TRP[v_TRP]) path_TRP.push_back(v_TRP);
    for(int i_TRP=path_TRP.size()-1; i_TRP>=0; i_TRP--) cout << path_TRP[i_TRP] << " ";
    cout << endl;
}

int main() 
{
    int n_TRP;
    cout << "Enter number of vertices: ";
    cin >> n_TRP;
    vector<vector<int>> graph_TRP(n_TRP, vector<int>(n_TRP));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for(int i_TRP=0;i_TRP<n_TRP;i_TRP++)
        for(int j_TRP=0;j_TRP<n_TRP;j_TRP++)
            cin >> graph_TRP[i_TRP][j_TRP];

    int start_TRP, end_TRP;
    cout << "Enter start node: ";
    cin >> start_TRP;
    cout << "Enter end node: ";
    cin >> end_TRP;

    dijkstra_TRP(graph_TRP, start_TRP, end_TRP);

    return 0;
}
