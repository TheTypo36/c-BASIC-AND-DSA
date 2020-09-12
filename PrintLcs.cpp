#include <bits/stdc++.h>
using namespace std;

set<char> p;
void printLcs(string s1,string s2){
    if(s1.length()==0||s2.length()==0){
        return ;
    }
    if(s1[0] == s2[0])
    {
        p.insert(s1[0]);
        printLcs(s1.substr(1),s2.substr(1));
    }else
    {
        printLcs(s1.substr(1),s2);
        printLcs(s1,s2.substr(1));
    }
    
}
void printLcsDp(string s1, string s2){
     int m = s1.length();
    int n = s2.length();

    vector<vector<int>> strg((m+1),vector<int>(n+1,0)) ;
    int i , j;
    for ( i = 0; i < m+1; i++)
    {
        for ( j = 0; j < n+1; j++)
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
    //cout << i << endl;
    string ans;
    
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }else{
            if(strg[i-1][j]<strg[i][j-1]){
                    j--;
            }else{
                i--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}


int main(){

    string s1;
    string s2;
    cin >> s1 >> s2;
    printLcs(s1,s2);
    for(auto no:p){
        cout << no << "";
    }
    cout << endl;
    
    printLcsDp(s1,s2);
}