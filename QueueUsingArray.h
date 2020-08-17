#include <bits/stdc++.h>
using namespace std;
template <typename T>
class QueueUsingArray
{

    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T data)
    {
        if (size == capacity)
        {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = this -> data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = this -> data[i];
                j++;
            }
            delete[] this -> data;
            this->data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity = 2 * capacity;
        }
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        this->data[nextIndex] = data;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!!" << endl ;
            return 0;
        }
        T ans = this->data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            nextIndex = 0;
            firstIndex = -1;
        }
        return ans;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is Emptyyyyyyy!!" << endl;
            return 0;
        }
        return this->data[firstIndex];
    }
};