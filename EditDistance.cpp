#include <bits/stdc++.h>
using namespace std;
int editDistanceDp(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **strg = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        strg[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        strg[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        strg[0][i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[m - i] == s2[n - j])
            {
                strg[i][j] = strg[i - 1][j - 1];
            }
            else
            {
                strg[i][j] = 1 + min(strg[i - 1][j - 1], min(strg[i - 1][j], strg[i][j - 1]));
            }
        }
    }
    return strg[m][n];
}
int editDistanceMemoization(string s1, string s2, int **strg)
{
    int m = s1.length();
    int n = s2.length();
    if (m == 0 && n == 0)
    {
        return 0;
    }
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }
    if (strg[m][n] != -1)
    {
        return strg[m][n];
    }
    int ans;
    if (s1[0] == s2[0])
    {
        ans = editDistanceMemoization(s1.substr(1), s2.substr(1), strg);
    }
    else
    {
        int r1 = 1 + editDistanceMemoization(s1.substr(1), s2, strg);
        int r2 = 1 + editDistanceMemoization(s1, s2.substr(1), strg);
        int r3 = 1 + editDistanceMemoization(s1.substr(1), s2.substr(1), strg);
        ans = min(r1, min(r2, r3));
    }
    strg[m][n] = ans;
    return ans;
}
int editDistance(string s1, string s2)
{
    if (s1.length() == 0 && s2.length() == 0)
    {
        return 0;
    }
    if (s1.length() == 0)
    {
        return s2.length();
    }
    if (s2.length() == 0)
    {
        return s1.length();
    }
    if (s1[0] == s2[0])
    {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    int del = 1 + editDistance(s1.substr(1), s2);
    int rep = 1 + editDistance(s1, s2.substr(1));
    int insert = 1 + editDistance(s1.substr(1), s2.substr(1));

    return min(del, min(rep, insert));
}
int main()
{

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;
    int **strg = new int *[s1.length() + 1];
    for (int i = 0; i <= s1.length(); i++)
    {
        strg[i] = new int[s2.length() + 1];
        for (int j = 0; j <= s2.length(); j++)
        {
            strg[i][j] = -1;
        }
    }
    cout << "DynamicProgramming Approach: " << editDistanceDp(s1, s2) << endl;
    cout << "Memoization Approach: " << editDistanceMemoization(s1, s2, strg) << endl;
    cout << "Recursive Approach: " << editDistance(s1, s2) << endl;
}