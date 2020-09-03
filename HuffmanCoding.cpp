#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> freqOf(string str){
    unordered_map<char,int> freq;
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i]]++;
        
    }
    return freq;
}
string huffmanCoding(string str){
    unordered_map<char,int> freq =   freqOf(str);
    
}
int main(){

    int n;
   cin >> n;

}