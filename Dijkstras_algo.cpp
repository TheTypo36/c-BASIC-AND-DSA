#include <bits/stdc++.h>
using namespace std;
int findMinVertex(int* distance, bool* visited, int n){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}
void dijkstra_algo(int **edges, int V)
{

    //int *dis = new int[V];
    bool *visited = new bool[V];
    int *weight = new int[V];
    for (int i = 0; i < V; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    weight[0] = 0;

    for (int i = 0; i < V-1; i++)
    {
        int a = findMinVertex(weight,visited,V);

        visited[a] = true;
        for (int j = 0; j < V; j++)
        {
            
            if (edges[i][j]!=0 && !visited[j])
            {
                int c_dis = weight[a] + edges[a][j];
                if (c_dis < weight[j])
                {
                    weight[j] = c_dis;
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << weight[i] << endl;
    }
    delete[] weight;
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
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    dijkstra_algo(edges, V);
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
