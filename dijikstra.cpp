// code to implement dijikstra algorithm
#include <bits/stdc++.h>
using namespace std;

// making function for the algorithm
void dijkstra(int source, int cost[20][20], int visited[20], int d[20], int n)
{
    int i, j, u, w, min;
    for (i = 1; i <= n; i++)
    { // initially marking each node as not visited
        visited[i] = 0;
        d[i] = cost[source][i];
    }

    visited[source] = 1;
    d[source] = 0;
    for (j = 2; j <= n; j++)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            if (!visited[i])
            { // checking if visited or not
                if (d[i] < min)
                {
                    min = d[i];
                    u = i;
                }
            }
        }
        visited[u] = 1;
        for (w = 1; w <= n; w++)
        { // implenting formulae for cost calculation
            if (cost[u][w] != 999 && visited[w] == 0)
            {
                if (d[w] > cost[u][w] + d[u])
                {
                    d[w] = cost[u][w] + d[u];
                }
            }
        }
    }
}

int main()
{
    int cost[20][20], visited[20], d[20], i, j, n, source;

    cout << "Enter the no of nodes: ";
    cin >> n;
    cout << "\nenter the adjancey cost matrix: \n";
    // taking input from the user in matrix form
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << "\nEnter the source node: ";
    cin >> source;
    dijkstra(source, cost, visited, d, n); // calling the function
    for (i = 1; i <= n; i++)
    {
        if (i != source)
        {
            cout << "\n shortest path from " << source << " to " << i << " is " << d[i] << endl;
            //  << source << i << d[i] << endl;
        }
    }
}