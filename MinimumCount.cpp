#include <bits/stdc++.h>
using namespace std;
int minCountDp(int n)
 {
     int * strg = new int[n+1];
     for (int i = 0; i <= n; i++)
     {
         /* code */
         strg[i] = INT_MAX;
     }
     
     //seeding 
     strg[0] = 0;
     strg[1] = 1;

     for (int i = 2 ; i <= n; i++)
     {
         for (int  j = 1;j*j <= i; j++)
         {
             if(i-(j*j)<0){
             continue;
         }
         int recur = 1+strg[i-(j*j)];
            strg[i] = min(strg[i],recur);
         }
         
         
     }
     return strg[n];
     

 }
int minCountMemoization(int n, int *strg)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (strg[n] != -1)
    {
        return strg[n];
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        int recur = 1 + minCountMemoization(n - (i * i), strg);
        ans = min(ans, recur);
    }
    strg[n] = ans;
    return strg[n];
}
int minCount(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        int recur = 1 + minCount(n - (i * i));
        ans = min(ans, recur);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    cout << "DynamicProgramming Approach: " << minCountDp(n) << endl;
    cout << "Memoization Approach: " << minCountMemoization(n, arr) << endl;
    cout << "Recursive Approach: " << minCount(n) << endl;
}
