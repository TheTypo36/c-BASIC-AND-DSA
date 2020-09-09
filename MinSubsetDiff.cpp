#include <bits/stdc++.h>
using namespace std;
bool subsetSumDp(int *input, int n, int sum)
{
    bool **strg = new bool *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        strg[i] = new bool[sum + 1];
    }
    //    memset(strg,-1,sizeof(strg));
    for (int i = 0; i < n + 1; i++)
    {
        strg[i][0] = true;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        strg[0][i] = false;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (input[i - 1] > j)
            {
                strg[i][j] = strg[i - 1][j];
            }
            else
            {
                strg[i][j] = strg[i - 1][j - input[i - 1]] || strg[i - 1][j];
            }
        }
    }
    return strg[n][sum];
}
int minSubsetDiff(int *input, int n, int sum)
{

    bool **strg = new bool *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        strg[i] = new bool[sum + 1];
    }

    for (int i = 0; i < sum + 1; i++)
    {
        strg[0][i] = false;
    }
    for (int i = 0; i < n + 1; i++)
    {
        strg[i][0] = true;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (input[i - 1] > j)
            {
                strg[i][j] = strg[i - 1][j];
            }
            else
            {
                strg[i][j] = strg[i - 1][j - input[i - 1]] || strg[i - 1][j];
            }
        }
    }
    vector<int> ans;
    for (int j = 0; j < ((sum + 1) / 2); j++)
    {
        if (strg[n][j] == true)
            ans.push_back(j);
    }
    int minDiff = INT_MAX;
    for (int i = 0; i < ans.size(); i++)
    {
        minDiff = min(minDiff, (sum - 2 * ans[i]));
    }
    return minDiff;
}
int main()
{
    int testcase = 0;
    cin >> testcase;
    while (testcase--)
    {

        int n;
        cin >> n;
        int *input = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += input[i];
        }
        if (sum % 2 == 0)
        {
            bool ans = subsetSumDp(input, n - 1, sum / 2);
            if (ans == true)
            {
                cout << 0 << endl;
                continue;
            }
        }
        cout << minSubsetDiff(input, n, sum) << endl;
    }
}