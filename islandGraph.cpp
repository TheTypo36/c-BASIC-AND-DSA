#include <bits/stdc++.h>
using namespace std;
void dfs(int** edges,int V,int sv,bool* visited){
    visited[sv] = true;
    for (int i = 1; i <=V; i++)
    {
        if(i==sv)
        continue;
        if(edges[sv][i]==1&&!visited[i]){
        
            dfs(edges,V,i,visited);
        }
    }
    
}
int solve(int n, int m, vector<int> u, vector<int> v)
{
    int **edges = new int *[n+1];
    for (int i = 0; i < n+1; i++)
    {
        edges[i] = new int[n+1];
        for (int j = 0; j < n+1; j++)
        {
          
            edges[i][j] = 0;
        }
        
    }
              

    for(int i =0 ; i < m; i++){
        int f = u[i];
        int s = v[i];
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n+1];
    for (int i = 0; i <=n ; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 1; i <=n; i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(edges,n,i,visited);
        }
    }
    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete [] edges;
    return count;
    
    
    
}
int main()
{
    int n, m;
    vector<int> u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        u.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solve(n, m, u, v) << endl;
}