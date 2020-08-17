#include <bits/stdc++.h>
using namespace std;

class StackUsingArrays
{
    int *arr;
    int nextIndex;
    int capacity;

public:
    StackUsingArrays(int totalNumber)
    {
        this->capacity = totalNumber;
        arr = new int[capacity];
        nextIndex = 0;
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
    void push(int data){
        if(nextIndex == capacity){
            cout << "stack is Full!"<< endl;
            return;
        }
        arr[nextIndex] =data;
        nextIndex++;
    }
    int pop(){
        if(this -> isEmpty()){
            cout << "stack is empty!" << endl;
        }
            nextIndex--;
            return arr[nextIndex];
    }
    int top(){
          if(this -> isEmpty()){
            cout << "stack is empty!" << endl;
        }
           
            return arr[nextIndex - 1];
    }

};
