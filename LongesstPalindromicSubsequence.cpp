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
int main(){

    string s;
    cin >> s;
    string a ;
    a = s;
    reverse(s.begin(),s.end());
    cout << lcsDp(a,s) << endl;

}