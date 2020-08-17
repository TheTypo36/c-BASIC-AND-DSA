#include <bits/stdc++.h>
using namespace std;
#include "stackUsingArrays.cpp"
int main(){
        StackUsingArrays<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
        s.push(70);
        s.push(80);
        s.push(90);
        s.push(100);
        s.push(11);
        
        cout << s.isEmpty() << endl;
        cout << s.size() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
 
 cout << s.isEmpty() << endl;
        cout << s.size() << endl;
}