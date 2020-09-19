#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
	int** edges = new int*[n+1];
    for(int i = 0; i < n+1;i++){
        edges[i] = new int[n+1];
        for(int j=0; j< n+1; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0 ; i < m; i++){
        int f = u[i];
        int s = v[i];
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int count = 0;
    for(int i = 1; i < n+1; i++){
        for(int j =1 ; j < n+1; j++){
            for(int k =1 ; k < n+1; k++){
                if(i==k)
                    continue;
                if(edges[i][j]==1&&edges[j][k]==1&&edges[i][k] == 1){
                    count++;
                }
            }
        }
    }
    return count/6;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}