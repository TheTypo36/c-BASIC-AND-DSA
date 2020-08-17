
#include "QueueUsingArray.h"

int main()
{

    QueueUsingArray<int> q(4);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

   // cout << "size of the queue : " << q.getSize() << endl;
    //cout << "front of the queue : " << q.front() << endl;
    
    cout << q.dequeue() << endl;

   // cout << "size of the queue : " << q.getSize() << endl;
    //cout << "front of the queue : " << q.front() << endl;

    q.enqueue(50);
   // cout << "size of the queue : " << q.getSize() << endl;
    //cout << "front of the queue : " << q.front() << endl;

    q.enqueue(60);

    q.enqueue(70);

    q.enqueue(80);

    q.enqueue(90);
    while (!q.isEmpty())
    {
        cout << "s : " << q.getSize() << endl;
   cout << "f : " << q.front() << endl;
   q.dequeue();

    }
    
    // cout << "size of the queue : " << q.getSize() << endl;
   // cout << "front of the queue : " << q.front() << endl;


}