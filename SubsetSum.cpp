#include <bits/stdc++.h>
using namespace std;
bool subsetSumDp(int* input, int n , int sum){
    bool **strg = new bool*[n+1];
    for (int i = 0; i < n+1; i++)
    {
        strg[i] = new bool[sum+1];
    }
    //    memset(strg,-1,sizeof(strg));
    for (int i = 0; i < n+1; i++)
    {
        strg[i][0] =true;
    }
    for (int i = 1; i < sum+1; i++)
    {
        strg[0][i] = false;
    }
    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j< sum+1; j++)
        {
            if(input[i-1]>j){
                strg[i][j] = strg[i-1][j];
            }
            else{
                strg[i][j]= strg[i-1][j-input[i-1]]||strg[i-1][j]; 
            }
        }

    }
    return strg[n][sum];
    
    
    
    
}
bool subsetSumMemoization(int *input, int n , int sum , int** strg)
{
    if(sum == 0)
    return true;
    if(n == 0)
    return false;

    if(strg[n][sum]!=-1){
        return strg[n][sum];
    }
    bool ans;
    if(input[n-1] > sum){
        ans = subsetSumMemoization(input,n-1,sum,strg);
    }
    else{
        int recurAns1 = subsetSumMemoization(input,n-1,sum-input[n-1],strg);
        int recurAns2 = subsetSumMemoization(input, n-1, sum,strg);
        ans = recurAns1 || recurAns2;
    }
    strg[n][sum] = ans;
    return ans;
}
bool subsetSum(int *input, int n, int sum)
{
     if(sum == 0){
        return true;
    }
    if(n==0){
        return false;
    }
   
    if(input[0]>sum){
        return subsetSum(input+1,n-1,sum);
    }else
    {
        bool ans1 = subsetSum(input+1,n-1,sum-input[0]);
        bool ans2 = subsetSum(input+1,n-1,sum);
        return ans1 || ans2;
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
    int Sum;
    cin >> Sum;
    int** strg=new int*[n+1];
    for (int i = 0; i < n+1; i++)
    {
        strg[i] = new int[Sum+1];
        for (int j = 0; j < Sum+1; j++)
        {
            strg[i][j] = -1;
        }
        
    }

    cout << "DynamicProgramming Appraoch: " << subsetSumDp(input,n,Sum) << endl;
    cout <<"Memoization Appraoch: " << subsetSumMemoization(input,n,Sum,strg) << endl;
    cout << "Recursive Approach: " << subsetSum(input, n, Sum) << endl;
    
}