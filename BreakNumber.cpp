#include <bits/stdc++.h>
using namespace std;
void helper(int n, int sum , string s)
{
    if(n >){
        return ;
    }
    if(n == sum){
        cout << s << endl;
        s="";
        return ;
    }
    for(int i = 1; i < n ; i++){

    stringstream ss ;
    ss << i;
    string c ;
    ss >> c;
        helper(n,sum+i,s+c+" ");
    }
}
    void printCombination(int n)
{
	helper(n,0,"");
}

int main(){

    int n;
   cin >> n;
                                    printCombination(n); 
}