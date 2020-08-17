#include "Node.cpp"
template <typename T>
class stackUsingLinkedList{
    Node<T> * head ;
    int size;
    public :
    stackUsingLinkedList(){
        head = NULL;
        size = 0;
    }
    int sizeOfs(){
        return this->size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void push (T data){
        Node<T> *newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;

        }else{
            newNode -> next = head;
            head = newNode;
        }
        size++;
    }
    T pop(){
        if(head == NULL){
            return 0;
        }
        T ans = head -> data;
        Node<T> * temp = head;
        head = head ->next;
        size --;
        delete temp;
        return ans;
    }
    T top(){
        return head -> data;
    }
};