#include <bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int max_value = INT_MIN;
    vector<vector<int>> strg(row,vector<int>(col,0));
    for(int i = 0; i < row;i++){
        for(int j =0 ; j< col; j++){
            if(i==0||j==0){
                if(arr[i][j]==0){
                    strg[i][j] = 1;
                }else{
                    strg[i][j] = 0;
                }
            }else{
                if(arr[i][j] == 1){
                    strg[i][j] = 0;
                }else{
                    strg[i][j] = min(strg[i-1][j-1],min(strg[i-1][j],strg[i][j-1]))+1;
                }
            }
            max_value=max(max_value,strg[i][j]);
        }
    }
    return max_value;
}
int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
