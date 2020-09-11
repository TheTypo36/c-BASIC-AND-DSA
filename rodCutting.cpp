#include <bits/stdc++.h>
using namespace std;
int rodCuttingRecur(vector<int>xyz, int n){
    if(n <=0){
        return 0;
    }
    int max_value = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_value = max(max_value, xyz[i]+rodCuttingRecur(xyz,n-i-1));
    }
    return max_value;
    
}
int rodCuttingDp(vector<int> xyz, int n)
{
    int strg[n+1];
    strg[0] =0;
    int max_val = INT_MIN;
    for (int i = 1; i <=n; i++)
    {
        for(int j = 0; j<i; j++){
            max_val = max( max_val, xyz[j]+strg[i-j-1]);
            strg[i]=max_val;
        }
    }
    return strg[n];
    
}
int main()
{

    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ans.push_back(x);
        }
        cout << "DP approach : " <<rodCuttingDp(ans, n) << endl;
        cout << "recurApproach: " << rodCuttingRecur(ans,n) << endl;
    }
}