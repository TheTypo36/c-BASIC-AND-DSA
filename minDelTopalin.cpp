#include <bits/stdc++.h>
using namespace std;
int lcs(string x, string y)
{
    int m = x.length();
    int n = y.length();
    vector<vector<int>> ans(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                ans[i][j] = 1 + ans[i - 1][j - 1];
            }
            else
            {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
            }
        }
    }
    return ans[m][n];
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        string a, s;
        cin >> a;
        s = a;
        reverse(a.begin(), a.end());
        cout << a.length() - lcs(a, s) << endl;
    }
}