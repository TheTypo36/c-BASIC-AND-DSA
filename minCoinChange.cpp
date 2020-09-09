#include <bits/stdc++.h>
using namespace std;

int minCoinChangeMemoization(int* coins, int n ,int value,int* strg)
{
    if(value == 0){
        return 0;
    }
    if(strg[value]!=-1){
        return strg[value];
    }
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(coins[i]<=value){
            result = min(result,1+minCoinChangeMemoization(coins,n,value - coins[i],strg));
        }
    }
    return strg[value] = result;
}
int minCoinChange(int* coins, int n , int value){
    if(value == 0)
    return 0;
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(coins[i]<= value){
            result = min(result,1+minCoinChange(coins,n,value - coins[i]));
        }

    }
    return result;
}
int main(){

    int n;
   cin >> n;
    int * coins  = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int value;
    cin >> value;
    int * strg = new int[value];

    for (int i = 0; i < value+1; i++)
    {
        strg[i] = -1;
    }
    
    cout << "Memoization Approach: " << minCoinChangeMemoization(coins,n,value,strg) << endl;
    cout << "Recursive Approach: " << minCoinChange(coins,n,value) << endl;

    
}