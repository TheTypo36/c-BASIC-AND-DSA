#include <bits/stdc++.h>
using namespace std;

void printSuperSeqDp(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> strg((m + 1), vector<int>(n + 1, 0));
    int i, j;
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            // cout << strg[i][j] <<" ";
            if (i == 0 || j == 0)
            {
                strg[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                strg[i][j] = 1 + strg[i - 1][j - 1];
            }
            else
            {
                strg[i][j] = max(strg[i - 1][j], strg[i][j - 1]);
            }
        }
        //cout << endl;
    }
    //cout << i << endl;
    string ans;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (strg[i - 1][j] < strg[i][j - 1])
            {
                ans.push_back(s2[j - 1]);
                j--;
            }
            else
            {
                ans.push_back(s1[i - 1]);
                i--;
            }
        }
    }
    while (j > 0)
    {
        ans.push_back(s2[j - 1]);
        j--;
    }

    while (i > 0)
    {
        ans.push_back(s1[i - 1]);
        i--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main()
{

    string a, b;
    cin >> a >> b;
    printSuperSeqDp(a, b);
}