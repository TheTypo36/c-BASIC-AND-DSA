#include <bits/stdc++.h>
using namespace std;
void DFS(int **edges, int V, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < V; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1 && !visited[i])
        {
            visited[i]=true;
            DFS(edges,V,i,visited);
        }
    }
}
bool isConnect(int **edges, int V)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    DFS(edges, V, 0, visited);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    delete[] visited;
    return true;
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
   
    if(isConnect(edges,V)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    
    return 0;
  

  return 0;
}