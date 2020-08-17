#include <bits/stdc++.h>
using namespace std;
#include "Node.cpp"
template <typename T>

class Queue
{
    Node<T> *head;
    Node<T> *tail;

    int size;

public:
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    void enqueue(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        this->size++;
    }
    T front()
    {
        if(isEmpty()){
            return 0;
        }
        return this->head -> data;
    }
    T dequeue(){
        if(isEmpty())
        {
            return 0;
        }
        T ans = head -> data;
        Node<int>* temp = head;
        head = head -> next;
        delete temp;
        return ans;
    }

};