#include <bits/stdc++.h>
using namespace std;
class Edges
{
public:
    int source;
    int destination;
    int weight;

    Edges()
    {
        this->source = 0;
        this->destination = 0;
        this->weight = 0;
    }
};
bool compare(Edges a, Edges b)
{
    return a.weight < b.weight;
}
int findParent(int v1, int* parent){
    if(v1==parent[v1]){
        return v1;
    }
    return findParent(parent[v1],parent);
}
void krushkals_Algo(int V, int E)
{
    vector<Edges> input(E);
    for (int i = 0; i < E; i++)
    {
        int source, destintaion, weight;
        cin >> source >> destintaion >> weight;
        input[i].source = source;
        input[i].destination = destintaion;
        input[i].weight = weight;
    }
    sort(input.begin(), input.end(), compare);

    vector<Edges> output(V - 1);
    int *parent = new int[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    int count = 0;

    int input_i;
    while (count != V - 1)
    {
        int v1 = input[input_i].source;
        int v2 = input[input_i].destination;
        int v1p = findParent(v1, parent);
        int v2p = findParent(v2, parent);
        if (v1p != v2p)
        {
            output[count] = input[input_i];

            count++;
            parent[v1p] = v2p;
        }
        input_i++;
    }
    vector<Edges>::iterator it;
    for (it = output.begin(); it != output.end(); it++)
    {   
        if(it->destination<it -> source)
        cout << it->destination << " " << it->source << " " << it->weight << endl;
        else
        cout << it->source << " " << it->destination << " " << it->weight << endl;

    }
    delete[] parent;
}
int main()
{
    int V, E;
    cin >> V >> E;

    krushkals_Algo(V, E);
    return 0;
}
