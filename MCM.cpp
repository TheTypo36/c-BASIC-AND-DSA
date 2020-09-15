#include <bits/stdc++.h>
using namespace std;
int solve(int* matrix, int i , int j,int**strg){
    if(i>=j){
        return 0;
    }
    if(strg[i][j]!=-1){
        return strg[i][j];
    }
    int min_val = INT_MAX;
    for (int k = i; k <=j-1; k++)
    {
        int temp = solve(matrix,i,k,strg) + solve(matrix,k+1,j,strg)+(matrix[i-1]*matrix[k]*matrix[j]);
        min_val= min(min_val,temp);
    }
    return strg[i][j] = min_val;
    
}
int main(){
 int n; 
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }
  int **strg = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        strg[i] = new int[n + 1];
        for (int j = 0; j < n+1; j++)
        {
         strg[i][j]=-1;
        }
        
    }


  cout << solve(p, 1,n,strg);
}