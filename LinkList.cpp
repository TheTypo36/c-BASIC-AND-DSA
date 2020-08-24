#include "Node.cpp"

Node<int> *takeinput()
{
    int data;
    cin >> data;

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    while (data != -1)
    {
        Node<int> *newNode = new Node<int>(data);
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
        cin >> data;
    }
    return head;
}
void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node<int> *insertAtIth(Node<int> *head, int i, int data)
{
    Node<int> *newNode = new Node<int>(data);

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node<int> *temp = head;
    Node<int> *prev = NULL;
    while (i-- && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {

        prev->next = newNode;
        newNode->next = temp;
    }
    return head;
}
Node<int>* midpoint(Node<int>* head){
  Node<int>* slow = head;
  Node<int>* fast = head -> next;

  while(fast!=NULL){
      while(fast -> next!=NULL){
          slow= slow -> next;
          fast = fast -> next -> next;
      }
      break;
  }

return slow;
}
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
    node * even = NULL;
    if( head -> data % 2 == 0){
        even -> data = head  -> data;
        even -> next = NULL;
        
    }
    node * temp = head;
    
        while( temp -> next != NULL){
            if( temp -> next -> data % 2 == 0){
            	if( even == NULL){
                    even -> data == temp -> next -> data;
                    even -> next == NULL;
                }else{
                    node * newNode=new node(temp -> next -> data);
                    even -> next = newNode;
                }
                temp = temp -> next -> next;
            }else{
            temp = temp -> next;
                }
        }
    if( head -> data % 2==0 ){
        head = head -> next;
    }
    temp -> next = even;
    return head;
***************/
pair<Node<int>*,Node<int>*> helper(Node<int>* head){
    if(head == NULL){
        pair<Node<int>*,Node<int>*> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
            pair<Node<int>*,Node<int>*> recurans = helper(head -> next);
        		
            pair<Node<int>*,Node<int>*> ans;

    if(head -> data%2 != 0){
        if(recurans.first!=NULL){
            head -> next =recurans.first;
            ans.first = head;
            ans.second = recurans.second;
        }else{
            ans.first = head;
            ans.second = head;
        }
    }else{
        if(recurans.first!=NULL){
          Node<int>* temp = recurans.first;
        Node<int>* prev = NULL;
            while(temp!=NULL&&temp->data%2!=0){
                prev = temp;
                temp =temp -> next;
                
            }
            if(temp!=NULL&&prev!=NULL){
                prev -> next = head;
                head -> next = temp ;
                ans.first = recurans.first;
                ans.second =recurans.second;
            }
            else if(temp!=NULL&&prev==NULL){
                head -> next = recurans.first;
                ans.first = head;
                ans.second = recurans.second;
            }
                else{
                recurans.second -> next = head ;
                ans.first=recurans.first;
                ans.second = head;
            }
        }else{
            ans.first = head;
            ans.second = head;
        }
        
    }
    ans.second->next= NULL;
    return ans;
}
Node<int>* arrange_LinkedList(Node<int>* head)
{
   	 return helper(head).first;
}

Node<int> *deleteIthNode(Node<int> *head, int i)
{
    Node<int> *temp = head;
    if (i == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    Node<int> *prev = NULL;
    while (i-- && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL)
    {
        prev->next = temp->next;
        delete temp;
    }
    return head;
}
Node<int> *printReverse(Node<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node<int> *recurans = printReverse(head->next);
    Node<int> *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return recurans;
}
int length(Node<int> *head)
{
    int len = 0;
    Node<int> *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int returnINt(Node<int> *head)
{
    if (head == NULL)
    {
        return 0;
    }
    if (head->next == NULL)
    {
        return head->data;
    }
    int sum = 0;
    Node<int> *temp = head;
    while (temp != NULL)
    {
        sum = (sum + temp->data) * 10;
        temp = temp->next;
    }
    return sum / 10;
}
int main(){
    Node<int>* head = takeinput();
    cout << midpoint(head)->data << endl;
}
