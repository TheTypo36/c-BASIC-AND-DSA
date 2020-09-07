#include <bits/stdc++.h>
using namespace std;
int helper(int x, int n, int cs, int cn ){
    if(x == cs){
        return 1;
    }
    if(x<cs)
    return 0;
    int count = 0;
    while(pow(cn,n)<=x){
    count += helper(x,n,cs+pow(cn,n),cn+1);
    cn++;

    }
    return count;
}
int allWays(int x, int n){
    return helper(x,n,0,1);
}
int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}
