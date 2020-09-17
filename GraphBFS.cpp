#include <bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int sv,bool* visited)
{
    
    queue<int> pending;
    visited[sv] = true;
    pending.push(sv);
    while (!pending.empty())
    {
        int front = pending.front();
        pending.pop();
        cout << front << " ";
        for (int i = 0; i < n; i++)
        {
            if(i==front){
                continue;
            }
         
            if (edges[front][i] == 1&& !visited[i])
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(int** edges,int n){
    bool * visited = new bool[n];
   for (int i = 0; i < n; i++)
   {
       visited[i] = false;
   }
   for (int i = 0; i < n; i++)
   {
       if(!visited[i])
       print(edges,n,i,visited);
   }
   delete [] visited;
   
}
int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int*[n];
   for (int i = 0; i < n; i++)
   {
       edges[i] = new int[n];
       for (int j = 0; j < n; j++)
       {
           edges[i][j] = 0;
       }
       
   }
   
   for (int i = 0; i < e; i++)
   {
       int f , s;
       cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
   }
   
   BFS(edges,n);
   for (int i = 0; i < n; i++)
   {
       delete [] edges[i];
   }
   delete [] edges;

   

   

    return 0;
}
/*
7
5
0 2
0 3
2 3
1 4
5 6

*/