#include <bits/stdc++.h>
using namespace std;
#include "PriorityQueue.h"
int main()
{
    priorityQueue q;
    q.insert(100);
    q.insert(10);
    q.insert(15);
    q.insert(4);
    q.insert(17);
    q.insert(21);
    q.insert(67);
    cout << q.getSize() << endl;
    cout << q.getMin() << endl;
    while (!q.isEmpty())
    {
        cout << q.removeMin() << " ";
    }
    cout << endl;
    
    /*
    for(int i = 99 ; i >= 0 ; i--){
        q.insert(i+1);
        cout << "Min: " << q.getMin() << endl;
    }
    cout << q.getSize()<< endl;
    for (int i = 0; i < 99; i++)
    {
        cout << "remove: " << q.removeMin() << endl;
    }
    */
    
}