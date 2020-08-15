#include "Node.cpp"
Node *arrange_LinkedList(Node *head)
{
    Node * oddhead = NULL;
    Node * oddtail = NULL;
    Node * evenhead = NULL;

    Node * eventail = NULL;
    while(head !=NULL){
            Node* newNode = new Node(head -> data);
        if( head -> data % 2== 0){
            if(evenhead == NULL){
            evenhead = newNode;
            eventail = newNode;
            }else{
                eventail -> next = newNode;
                eventail = eventail -> next; 
            }
        }else{
            if(oddhead == NULL){
            oddhead = newNode;
            oddtail = newNode;
            }else{
                oddtail -> next = newNode;
                oddtail = oddtail -> next; 
            }
        }
        head=head->next;
    }
   oddtail -> next = evenhead;
    return oddhead;
    
}
Node* takeinput(){
    int data;
    cin>>data;
    Node* head=NULL,*tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL)                  {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
