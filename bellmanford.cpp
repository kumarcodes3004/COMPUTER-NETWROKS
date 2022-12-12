
#include <bits/stdc++.h>
using namespace std;
int bellman_Ford(int G[100][100], int V, int E, int edge[100][2])
{
    int i, u, v, k, distance[100], S, flag = 1;
    for (i = 0; i < V; i++)
        distance[i] = 1000;    // initializing the distances
    cout << "Enter source : "; // Entering the Source
    cin >> S;                  // Taking the source
    distance[S - 1] = 0;
    for (i = 0; i < V - 1; i++)
    {
        for (k = 0; k < E; k++)
        {
            u = edge[k][0];
            v = edge[k][1];
            if (distance[u] + G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v]; // Updating the distance
        }
    }
    for (k = 0; k < E; k++)
    {
        u = edge[k][0];
        v = edge[k][1];
        if (distance[u] + G[u][v] < distance[v])
            flag = 0; // if negative exists, then flag set to zero
    }
    if (flag)
        for (i = 0; i < V; i++)
            cout << "Distance from source " << S << " to vertex " << i + 1 << "is " << distance[i] << endl; // Printing the shortest paths
    return flag;                                                                                            // flag to check whether negative cycle exists or not
}
int main()
{
    int V, edge[100][2], G[100][100], i, j, k = 0;
    cout << "Enter no. of vertices: ";
    cin >> V;
    cout << "Enter graph in matrix form:\n";
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
        {
            cin >> G[i][j];                       // taking the input
            if (G[i][j] != 0)                     // if there exits a path from i to j
                edge[k][0] = i, edge[k++][1] = j; // init. the edge matrix
        }
    if (bellman_Ford(G, V, k, edge))
        cout << "No negative weight cycle exists" << endl;
    return 0;
}