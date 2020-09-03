#include <bits/stdc++.h>
using namespace std;
long long stairCaseDp(int n)
{
   long long *strg = new long long[n+1];
    //seeding
    strg[0] = 1;
    strg[1] = 1;
    strg[2] = 2;
    for(int i = 3 ; i <= n ; i++){
        strg[i]  = strg[i-1] +strg[i-2] + strg[i-3];

    }
    return strg[n];

}
long long stairCaseMemoization(int n, int *strg)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (strg[n] != -1)
    {
        return strg[n];
    }
    int ans = stairCaseMemoization(n - 1, strg) + stairCaseMemoization(n - 2, strg) + stairCaseMemoization(n - 3, strg);
    strg[n] = ans;
    return strg[n];
}
long long staircase(long long n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
        return 1;
    long long f1 = staircase(n - 1);
    long long f2 = staircase(n - 2);
    long long f3 = staircase(n - 3);
    long long ans = f1 + f3 + f2;
    return ans;
}
int main()
{

    long long n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    cout << "DynamicProgramming Approach: " << stairCaseDp(n) << endl;
    cout << "Memoization Approach: " << stairCaseMemoization(n, arr) << endl;
    cout << "Recursive Approach: " << staircase(n) << endl;
}