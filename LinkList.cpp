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
