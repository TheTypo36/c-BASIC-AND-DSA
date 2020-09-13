#include <bits/stdc++.h>
using namespace std;

int LongRepSubSeq(string s1){
    string s2 = s1;
    int m = s1.length();
    int n = s1.length();
    int i,j;
    vector<vector<int>> strg(m+1,vector<int>(n+1,0));
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(s1[i-1]==s2[j-1]&&i!=j){
                strg[i][j] = 1+strg[i-1][j-1];
            }else{
                strg[i][j]= max(strg[i-1][j],strg[i][j-1]);
            }
        }
        
    }
    return strg[m][n];
}
int main(){
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
    
    int n;
   cin >> n;
    string s;
    cin >> s;
    cout << LongRepSubSeq(s) << endl;
    }
    
}