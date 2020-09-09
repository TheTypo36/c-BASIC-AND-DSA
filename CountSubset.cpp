#include <bits/stdc++.h>
using namespace std;
int countSubsetDp(int *input, int n, int sum)
{
    int strg[n+1][sum+1];
    //memset(strg,-1,sizeof(strg));
  for(int i = 0; i< n+1;i++){
      strg[i][0] = 1;
  }
  for (int  i = 1; i < sum+1; i++)
  {
      /* code */
      strg[0][i] = 0;
  }
  
    for (int  i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(input[i-1]>j){
                strg[i][j] = strg[i-1][j];
            }else{
                strg[i][j] = strg[i-1][j]+strg[i-1][j-input[i-1]];
            }
        }
        
    }
    return strg[n][sum];
    
}
int countSubsetMemoization(int *input, int n, int sum, int **strg)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (strg[n][sum] != -1)
    {
        return strg[n][sum];
    }
    int ans = 0;
    if (sum < input[n - 1])
    {
        ans = countSubsetMemoization(input, n - 1, sum, strg);
    }
    else
    {

        int a = countSubsetMemoization(input, n - 1, sum - input[n - 1], strg);
        int b = countSubsetMemoization(input, n - 1, sum, strg);
        ans = a + b;
    }
    return strg[n][sum] = ans;
}
int countSubset(int *input, int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    int result = INT_MAX;
    if (sum < input[n - 1])
    {
        return countSubset(input, n - 1, sum);
    }
    else
    {
        int ans1 = 0, ans2 = 0;
        ans1 = countSubset(input, n - 1, sum - input[n - 1]);
        ans2 = countSubset(input, n - 1, sum);
        return ans1 + ans2;
    }
}
int main()
{

    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int sum;
    cin >> sum;
    int **strg = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        strg[i] = new int[sum + 1];
        for (int j = 0; j < sum + 1; j++)
        {
            strg[i][j] = -1;
        }
    }
    cout <<"Dynamic Programming Approach: " << countSubsetDp(input,n,sum) << endl;
    cout << "Memoization Approach: " << countSubsetMemoization(input, n, sum, strg) << endl;
    cout << "Recursive Approach: " << countSubset(input, n, sum) << endl;
}