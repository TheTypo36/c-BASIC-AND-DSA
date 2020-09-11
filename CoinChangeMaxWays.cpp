#include <bits/stdc++.h>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
	int **strg = new int*[numDenominations+1];
    for(int i = 0 ; i < numDenominations+1; i++){
        strg[i] = new int[value+1];
    }
    for(int i = 0; i < value+1; i++){
        strg[0][i] = 0;
    }
    for(int i = 0; i < numDenominations+1; i++)
    {
		strg[i][0] = 1; 
    }
    for(int i = 1; i < numDenominations+1; i++){
        for(int j = 1; j < value+1; j++){
          if(denominations[i-1] > j){
                strg[i][j] = strg[i-1][j];
            }else{
                strg[i][j] =  strg[i][j-denominations[i-1]]+strg[i-1][j];
            }
        }
    }
    return strg[numDenominations][value];
}
int coinChangeMaxWaysRecur(int* coins, int n , int value){
    if(value==0)
    {
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(coins[n-1]>value){
        return coinChangeMaxWaysRecur(coins,n-1,value);
    }else{
        return coinChangeMaxWaysRecur(coins,n,value-coins[n-1])+coinChangeMaxWaysRecur(coins,n-1,value);
    }
}
int main(){

    int n;
   cin >> n;
    int * coins= new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int value;
    cin >> value;
    cout << "Dp Approach: " << countWaysToMakeChange(coins,n,value) << endl;
    cout << "Recursive Approach: " << coinChangeMaxWaysRecur(coins,n,value) << endl;
    
}