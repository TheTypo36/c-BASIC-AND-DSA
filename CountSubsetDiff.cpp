#include <bits/stdc++.h>
using namespace std;

int CountSubsetDiff(int *input, int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += input[i];
    }
    //cout <<"sum: " << sum << endl;
    int s1 = (sum + diff) / 2;
    //cout <<"s1: " << s1 << endl;
    int **strg = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        strg[i] = new int[s1 + 1];
    }
    for (int i = 0; i < s1+1; i++)
    {
        strg[0][i] = 0;
    }
    for (int i = 0; i < n+1; i++)
    {
        strg[i][0] = 1;
    }
    
    
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < s1 + 1; j++)
        {
            if(input[i-1]>j){
                strg[i][j] = strg[i-1][j];
            }else{
                strg[i][j] = strg[i-1][j] + strg[i-1][j-input[i-1]];
            }
        }
    }
    return strg[n][s1];
}
int main()
{

    int n;
    cin >> n;
    int* input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int diff;
    cin >> diff;
    cout << CountSubsetDiff(input,n,diff) << endl;
    
}