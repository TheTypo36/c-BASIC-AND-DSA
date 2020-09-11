#include <bits/stdc++.h>
using namespace std;
int knapSack( int *wt, int *val, int n, int W) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max( 
                    val[i - 1] + K[i][w - wt[i - 1]], 
                    K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
} 
int unboundedKnapsack(int *weight, int *value, int n, int W)
{
    if(W == 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(weight[i]<=W){
        ans = max(ans, value[i]+unboundedKnapsack(weight,value,n,W-weight[i]));
        }
    }
    return ans;
}
int main()
{

    int n;
    cin >> n;
    int W = 0;
    cin >> W;
    int *weight = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int *value = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cout << knapSack(weight, value, n, W) << endl;
    cout << unboundedKnapsack(weight,value, n, W) << endl;
}
