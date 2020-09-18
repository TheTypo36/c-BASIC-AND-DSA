#include <bits/stdc++.h>
using namespace std;
vector<int> getPath(int**edges,int V, int v1,int v2,bool* visited){
    if(v1==v2){
        vector<int> ans;
        ans.push_back(v1);
        return ans;
    }
    unordered_map<int,int> map;
    queue<int> pending;
    pending.push(v1);
    visited[v1] = true;
    while (!pending.empty())
    {
        int front = pending.front();
        pending.pop();
        for (int i = 0; i < V; i++)
        {
            if(edges[front][i]==1&&!visited[i]){
                visited[i] = true;
                pending.push(i);
                map[i]=front;
                if(i==v2){
                    break;
                }
            }
        }
        
    }
    vector<int> ans;
    if(map.count(v2)<1){
        return ans;
    }else{
        ans.push_back(v2);
        int i = v2;
        while (i!=v1)
        {
            int who = map[i];
            ans.push_back(who);
            i=who;
        }
      //  ans.push_back(v1);
        
    }
    return ans;
}
int main()
{
  int V, E, v1, v2;
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
   
    cin >> v1 >> v2;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    vector<int> ans = getPath(edges, V, v1, v2, visited);
    for(int i = 0 ; i < ans.size();i++){
        cout << ans[i] << " " ;
    }
    cout << endl;
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    return 0;
  

  return 0;
}
