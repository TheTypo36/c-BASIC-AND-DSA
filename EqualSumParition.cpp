#include <bits/stdc++.h>
using namespace std;
bool subsetSumDp(int* input, int n , int sum){
    bool **strg = new bool*[n+1];
    for (int i = 0; i < n+1; i++)
    {
        strg[i] = new bool[sum+1];
    }
    //    memset(strg,-1,sizeof(strg));
    for (int i = 0; i < n+1; i++)
    {
        strg[i][0] =true;
    }
    for (int i = 1; i < sum+1; i++)
    {
        strg[0][i] = false;
    }
    for (int i = 1; i < n+1; i++)
    {
        for(int j = 1; j< sum+1; j++)
        {
            if(input[i-1]>j){
                strg[i][j] = strg[i-1][j];
            }
            else{
                strg[i][j]= strg[i-1][j-input[i-1]]||strg[i-1][j]; 
            }
        }

    }
    return strg[n][sum];
    
    
    
    
}
int main() {
	int testcase;
	cin >> testcase;
	while(testcase--){
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int Sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        Sum+=input[i];
    }
    if(Sum%2!=0){
    cout << "NO" << endl; 
    }    else{
        Sum = Sum/2;
    
    bool ans = subsetSumDp(input, n -1 , Sum);
    if(ans == true)
    cout << "YES" << endl;
    else 
    cout << "NO" << endl;
    }   
	}
}