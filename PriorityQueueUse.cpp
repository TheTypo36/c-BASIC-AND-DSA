#include <bits/stdc++.h>
using namespace std;
#include "PriorityQueue.h"
int main()
{
    priorityQueue q;
    for(int i = 99 ; i >= 0 ; i--){
        q.insert(i+1);
        cout << "Min: " << q.getMin() << endl;
    }
    cout << q.getSize()<< endl;
    for (int i = 0; i < 99; i++)
    {
        cout << "remove: " << q.removeMin() << endl;
    }
    
}