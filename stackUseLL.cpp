#include <iostream>
using namespace std;
#include "stackUsingLinkedList.cpp"

int main(){
stackUsingLinkedList<int> s;
s.push(5);
s.push(4);

s.push(3);

s.push(2);

s.push(1);

cout <<s.top() << endl;
cout <<s.pop() << endl;
cout <<s.top() << endl;
cout << s.sizeOfs()<< endl;

}