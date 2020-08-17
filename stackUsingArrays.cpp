#include <bits/stdc++.h>
using namespace std;

class StackUsingArrays
{
    int *arr;
    int nextIndex;
    int capacity;

public:
    StackUsingArrays()
    {
        this->capacity = 4;
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
            int * newArr = new int[2*capacity];
            int i=0;
            while(i<capacity){
               newArr[i] = arr[i];
               i++;
            }
            delete [] arr;
            arr=newArr;
            capacity=2*capacity;
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
