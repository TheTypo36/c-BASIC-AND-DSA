#include <bits/stdc++.h>
using namespace std;
int minCostPathDP(int **input, int m, int n)
{
    int **strg = new int *[m];
    for (int i = 0; i < m; i++)
    {
        strg[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            strg[i][j] = 0;
        }
    }
    int sum =0;
    for (int i = 0; i < m; i++)
    {
        sum +=input[i][0];
        strg[i][0] =sum; 
       // cout << "row: "<< i << " col: "<<0<<" :"<<strg[i][0] << endl;
    }
    sum = input[0][0];
    for (int j = 1; j < n; j++)
    {
        sum+=input[0][j];
        strg[0][j] = sum;
       // cout <<"row: "<<0<<" col: "<<j<<" :"<< strg[0][j] << endl;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            strg[i][j] = input[i][j] + min(strg[i-1][j-1],min(strg[i-1][j],strg[i][j-1]));
        }
        
    }
    return strg[m-1][n-1];
    
    
}
int minCostMemoization(int **input, int m, int n, int **strg)
{
    if (m == 0 && n == 0)
    {
        return input[m][n];
    }
    if (m < 0)
    {
        return INT_MAX;
    }
    if (n < 0)
    {
        return INT_MAX;
    }
    if (strg[m][n] != -1)
    {
        return strg[m][n];
    }
    int recur1 = minCostMemoization(input, m - 1, n, strg);
    int recur2 = minCostMemoization(input, m - 1, n - 1, strg);
    int recur3 = minCostMemoization(input, m, n - 1, strg);
    strg[m][n] = input[m][n] + min(recur1, min(recur2, recur3));
    return strg[m][n];
}
int minCostPath(int **input, int m, int n)
{
    if (m == 0 && n == 0)
    {
        return input[m][n];
    }
    if (m < 0)
    {
        return INT_MAX;
    }
    if (n < 0)
    {
        return INT_MAX;
    }
    int c1 = minCostPath(input, m - 1, n);
    int c2 = minCostPath(input, m, n - 1);
    int c3 = minCostPath(input, m - 1, n - 1);
    int mycost = input[m][n] + min(c1, min(c2, c3));
    return mycost;
}
int main()
{

    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        /* code */
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    int **strg = new int *[m];
    for (int i = 0; i < m; i++)
    {
        strg[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            strg[i][j] = -1;
        }
    }
    
    cout << "DynamicProgramming Approach: " << minCostPathDP(input, m, n) << endl;
    cout << "Memoization Approach: " << minCostMemoization(input, m - 1, n - 1, strg) << endl;
    cout << "Recursive Approach: " << minCostPath(input, m - 1, n - 1) << endl;
}