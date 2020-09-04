#include <bits/stdc++.h>
using namespace std;
int balancedBTsDP(int h)
{
    int *strg = new int[h + 1];
    strg[0] = 1;
    strg[1] = 1;
    int mod = (int)(pow(10,9)+7);
    for (int i = 2; i <= h; i++)
    {
        int x = strg[i - 1];
        int y = strg[i - 2];
        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2 * (long)(x)*y) % mod);

        strg[i] = (temp1 + temp2) % mod;
    }
    return strg[h];
}
int balancedBTsMemoization(int h, int *strg)
{
    if (h <= 1)
    {
        return 1;
    }
    if (strg[h] != -1)
    {
        return strg[h];
    }
    int mod = (int)(pow(10, 9) + 7);
    int x = balancedBTsMemoization(h - 1, strg);
    int y = balancedBTsMemoization(h - 2, strg);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);

    strg[h] = (temp1 + temp2) % mod;
}
int balancedBTs(int h)
{
    if (h <= 1)
    {
        return 1;
    }
    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    int ans = (temp1 + temp2) % mod;
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
    cout << "DynamicProgramming Approach: " << balancedBTsDP(n) << endl;
    cout << "Memoization Approach: " << balancedBTsMemoization(n, arr) << endl;
    cout << "Recursive Approach: " << balancedBTs(n) << endl;
}