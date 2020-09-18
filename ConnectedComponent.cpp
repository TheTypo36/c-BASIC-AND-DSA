#include <bits/stdc++.h>
using namespace std;
void bfs(int **edges, int V, int sv, vector<int> &ans, bool *visited)
{
    visited[sv] = true;
    ans.push_back(sv);
    for (int i = 0; i < V; i++)
    {
        if(i==sv)
        continue;
        if(edges[sv][i] == 1&& !visited[i]){
            bfs(edges,V,i,ans,visited);
        }
    }
    
}
void visited(int **edges, int V)
{
    vector<vector<int>> ans;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> s;
            bfs(edges, V, i, s, visited);
            ans.push_back(s);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        vector<int> print = ans[i];
        for (int j = 0; j < print.size(); j++)
        {
            cout << print[j] << " ";
        }
        cout << endl;
    }
    delete[] visited;
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

    visited(edges, V);
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}