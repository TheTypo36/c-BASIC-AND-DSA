#include <bits/stdc++.h>
#define NMAX 55
using namespace std;
void dfs(char cake[NMAX][NMAX],int n,int i, int j, bool** visited,int c){
	visited[i][j] = true;
    if (i - 1 >= 0 && cake[i - 1][j] == '1' && !visited[i - 1][j])
    {
         dfs(cake,n,i-1,j,visited,c+1);
    }
    if (j - 1 >= 0 && cake[i][j - 1] == '1' && !visited[i][j - 1])
    {
         dfs(cake,n,i,j-1,visited,c+1);

    }
    if (i + 1 < n && cake[i + 1][j] == '1' && !visited[i + 1][j])
    {
         dfs(cake,n,i+1,j,visited,c+1);

    }
    if (j + 1 < n && cake[i][j + 1] == '1' && !visited[i][j + 1])
    {
         dfs(cake,n,i,j+1,visited,c+1);
    }
    if (i - 1 >= 0 && j - 1 >= 0 && cake[i - 1][j - 1] == '1' && !visited[i - 1][j - 1])
    {
         dfs(cake,n,i-1,j-1,visited,c+1);

    }
    if (i + 1 < n && j + 1 < n && cake[i + 1][j + 1] == '1' && !visited[i + 1][j + 1])
    {
         dfs(cake,n,i+1,j+1,visited,c+1);
    }
    if (i - 1 >= 0 && j + 1 < n && cake[i - 1][j + 1] =='1' && !visited[i - 1][j + 1])
    {
         dfs(cake,n,i-1,j+1,visited,c+1);
    }
    if (i + 1 < n && j - 1 >= 0 && cake[i + 1][j - 1] == '1' && !visited[i + 1][j - 1])
    {
                 dfs(cake,n,i+1,j-1,visited,c+1);

    }
}
void initialise(bool** visited,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}
int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    bool** visited = new bool*[n];
    for(int i = 0 ; i < n; i++){
        visited[i] = new bool[n];
        
    }
    initialise(visited,n);
    int ans = INT_MIN;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] = '1'){
                int count = 0;
                dfs(cake,n,i,j,visited,count);
                ans=max(ans,count);
            }
            initialise(visited,n);
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