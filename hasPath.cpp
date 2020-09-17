#include <bits/stdc++.h>
using namespace std;
bool DFShasPath(int **edges, int n, int s, int e, bool *visited)
{
    if (edges[s][e] == true)
    {
        return true;
    }
    visited[s] = true;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (i == s)
        {
            continue;
        }
        if (!visited[i])
        {
            ans = DFShasPath(edges, n, i, e, visited);
        }
    }
    if (ans == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool BFShasPath(int **edges, int n, int start, int end, bool *visited)
{
    queue<int> pending;
    pending.push(start);
    visited[start] = true;
    while (!pending.empty())
    {
        int front = pending.front();
        if (edges[front][end] == 1)
            return true;
        for (int i = 0; i < n; i++)
        {
            if (i == front)
            {
                continue;
            }
            if (edges[front][i] == 1 && !visited[i])
            {
                pending.push(i);
                visited[i] == true;
            }
        }
    }
}
int main()
{

    int n;
    cin >> n;
    int e;
    cin >> e;
    int start, end;
    cin >> start >> end;
    int **edges = new int *[n];
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cout << DFShasPath(edges, n, start, end, visited) << endl;
    cout << BFShasPath(edges, n, start, end, visited) << endl;
    for (int i = 0; i < n; i++)
    {
        delete edges[i];
    }
    delete[] edges;
}