#include <bits/stdc++.h>
using namespace std;
template <typename T>
class StackUsingArrays
{
    T *arr;
    int nextIndex;
    int capacity;

public:
    StackUsingArrays()
    {
        this->capacity = 4;
        arr = new T[capacity];
        nextIndex = 0;
    }
    T size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
    void push(T data){
        if(nextIndex == capacity){
            T * newArr = new T[2*capacity];
            T i=0;
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
    T pop(){
        if(this -> isEmpty()){
            cout << "stack is empty!" << endl;
            return 0;
        }
            nextIndex--;
            return arr[nextIndex];
    }
    T top(){
          if(this -> isEmpty()){
            cout << "stack is empty!" << endl;
            return 0;
        }
           
            return arr[nextIndex - 1];
    }

};
