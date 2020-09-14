#include <bits/stdc++.h>
using namespace std;
bool SeqPattrnMatching(string a, string b){
    if(a.length() == 0){
        return true;

    }
    if(b.length() == 0){
        return false;
    }
    if(a[0]==b[0]){
        return SeqPattrnMatching(a.substr(1),b.substr(1));
    }else{
        return SeqPattrnMatching(a,b.substr(1));
    }
}
int main(){

    string a,b;
    cin >> a >> b;
    cout << SeqPattrnMatching(a,b) << endl;

}