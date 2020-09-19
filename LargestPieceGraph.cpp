#include <bits/stdc++.h>
#define NMAX 55
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int dfs(char cake[NMAX][NMAX],int n,int i, int j, bool** visited){
	visited[i][j] = true;
    int ans = 0;
    if (i - 1 >= 0 && cake[i - 1][j] == '1' && !visited[i - 1][j])
    {
         ans=ans+dfs(cake,n,i-1,j,visited);
    }
    if (j - 1 >= 0 && cake[i][j - 1] == '1' && !visited[i][j - 1])
    {
    	ans=ans+dfs(cake,n,i,j-1,visited);

    }
    if (i + 1 < n && cake[i + 1][j] == '1' && !visited[i + 1][j])
    {
        ans=ans+dfs(cake,n,i+1,j,visited);

    }
    if (j + 1 < n && cake[i][j + 1] == '1' && !visited[i][j + 1])
    {
         ans=ans+dfs(cake,n,i,j+1,visited);
    }
   return ans+1;
}
int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    bool** visited = new bool*[n];
    for(int i = 0 ; i < n; i++){
        visited[i] = new bool[n];
          for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    int ans = INT_MIN;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] == '1'&&!visited[i][j]){
               
                ans = max(ans,dfs(cake,n,i,j,visited));
              
            }
        }
    }
    return ans;
}
char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}