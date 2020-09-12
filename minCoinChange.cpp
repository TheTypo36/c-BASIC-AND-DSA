#include <bits/stdc++.h>
using namespace std;
int minCoinChangeDp(int *coins, int n, int value)
{
    int **strg = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        strg[i] = new int[value + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < value + 1; j++)
        {
            if (i == 0)
            {
                strg[i][j] = INT_MAX - 1;
            }
            if (j == 0)
            {
                strg[i][j] = 0;
            }
            if (i == 1 && j > 0)
            {
                if (j % coins[0] == 0)
                {
                    strg[i][j] = j / coins[0];
                }
                else
                {
                    strg[i][j] = INT_MAX - 1;
                }
            }
        }
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < value + 1; j++)
        {
            if (coins[i - 1] > j)
            {
                strg[i][j] = strg[i - 1][j];
            }
            else
            {
                strg[i][j] = min(strg[i - 1][j], 1 + strg[i][j - coins[i - 1]]);
            }
        }
    }

    return strg[n][value];
}
int minCoinChangeMemoization(int *coins, int n, int value, int *strg)
{
    if (value == 0)
    {
        return 0;
    }
    if (strg[value] != -1)
    {
        return strg[value];
    }
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= value)
        {
            result = min(result, 1 + minCoinChangeMemoization(coins, n, value - coins[i], strg));
        }
    }
    return strg[value] = result;
}
int minCoinChange(int *coins, int n, int value)
{
    if (value == 0)
        return 0;
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= value)
        {
            result = min(result, 1 + minCoinChange(coins, n, value - coins[i]));
        }
    }
    return result;
}
int main()
{

    int n;
    cin >> n;
    int *coins = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int value;
    cin >> value;
    int *strg = new int[value];

    for (int i = 0; i < value + 1; i++)
    {
        strg[i] = -1;
    }
    cout << "Dp Approach: " << minCoinChangeDp(coins, n, value) << endl;
    cout << "Memoization Approach: " << minCoinChangeMemoization(coins, n, value, strg) << endl;
    cout << "Recursive Approach: " << minCoinChange(coins, n, value) << endl;
}