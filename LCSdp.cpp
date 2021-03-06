#include <bits/stdc++.h>
using namespace std;
int lcsDp(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> strg((m+1),vector<int>(n+1,0)) ;
    
    for (int i = 0; i < m+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
           // cout << strg[i][j] <<" ";
            if(i==0||j==0){
                strg[i][j]=0;
            }else if(s1[i-1]==s2[j-1]){
                strg[i][j] = 1+strg[i-1][j-1];
            }else{
                strg[i][j] = max(strg[i-1][j],strg[i][j-1]);
            }
        }
        //cout << endl;
    }
    
    return strg[m][n];
}
int lcsMemoization(string s1, string s2, int **strg)
{
    if (s1.length() == 0 || s2.length() == 0)
    {
        return 0;
    }
    if (strg[s1.length()][s2.length()] != -1)
    {
        return strg[s1.length()][s2.length()];
    }
    int ans;
    if (s1[0] == s2[0])
    {
        ans = 1 + lcsMemoization(s1.substr(1), s2.substr(1), strg);
    }
    else
    {
        int r1 = lcsMemoization(s1.substr(1), s2, strg);
        int r2 = lcsMemoization(s1, s2.substr(1), strg);
        ans = max(r1, r2);
    }
    strg[s1.length()][s2.length()] = ans;
    return ans;
}
int lcs(string s1, string s2)
{
    if (s1.length() == 0 || s2.length() == 0)
    {
        return 0;
    }
    if (s1[0] == s2[0])
    {
        return 1 + lcs(s1.substr(1), s2.substr(1));
    }
    else
    {
        int r1 = lcs(s1.substr(1), s2);
        int r2 = lcs(s1, s2.substr(1));
        return max(r1, r2);
    }
}
int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    int **strg = new int *[s1.length() + 1];
    for (int i = 0; i <= s1.length(); i++)
    {
        strg[i] = new int[s2.length() + 1];
        for (int j = 0; j <= s2.length(); j++)
        {
            strg[i][j] = -1;
        }
    }
    cout << "DynamicProgramming Approach: " << lcsDp(s1, s2) << endl;
    cout << "Memoization Approach: " << lcsMemoization(s1, s2, strg) << endl;
    cout << "Recursive Approach: " << lcs(s1, s2) << endl;
}