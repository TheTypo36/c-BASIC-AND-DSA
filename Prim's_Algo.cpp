#include <bits/stdc++.h>
using namespace std;
void prims_algo(int **edges, int V, int E)
{
    int *parent = new int[V];
    int *weight = new int[V];
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {

        weight[i] = INT_MAX;
        visited[i] = false;
    }
    parent[0] = -1;
    weight[0] = 0;
    for (int i = 0; i < V; i++)
    {
        int a = -1;
        int minW= INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (weight[i] < minW && !visited[i])
            {
                a = i;
                minW =  weight[i];
            }
        }

        visited[a] = true;
        for (int j = 0; j < V; j++)
        {
            if (a == j)
                continue;
            if (edges[a][j] > 0 && !visited[j])
            {
                if (weight[j] > edges[a][j])
                {
                    weight[j] = edges[a][j];
                    parent[j] = a;
                }
            }
        }
    }
    cout << endl;
    for (int i = 1; i < V; i++)
    {
        if (i < parent[i])
        {
            cout << i << " " << parent[i] << " " << edges[i][parent[i]] << endl;
        }
        else
        {
            cout << parent[i] << " " << i << " " << edges[i][parent[i]] << endl;
        }
    }
    delete[] visited;
    delete[] weight;
    delete[] parent;
}
int main()
{
    int V, E;
    cin >> V >> E;
    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    prims_algo(edges, V, E);

    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
