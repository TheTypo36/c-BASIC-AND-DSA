#include <bits/stdc++.h>
using namespace std;
int LcStringDp(string s1,string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> strg(m+1,vector<int>(n+1,0));
    int max_value= INT_MIN;
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(s1[i-1]==s2[j-1]){
                strg[i][j]=1+strg[i-1][j-1];
                max_value = max(strg[i][j],max_value);
            }else
            {
                strg[i][j] = 0;
            }
            
        }
        
    }
    return max_value;
}
int LcString(string s1,string s2,int count){
    if(s1.length()==0 || s2.length() == 0 ){
        return count;
    }
    if(s1[0] == s2[0]){
        count = LcString(s1.substr(1),s2.substr(1),count+1);
    }
    int x = LcString(s1.substr(1),s2,0);
    int y = LcString(s1,s2.substr(1),0);
    count = max(count,max(x,y));
    return count;
}
int main(){

    string s1, s2;
    cin >> s1 >> s2;
    cout << "Dp Approach: " << LcStringDp(s1,s2) << endl;
    cout << "Recursive Approach: " << LcString(s1,s2,0) << endl;

}