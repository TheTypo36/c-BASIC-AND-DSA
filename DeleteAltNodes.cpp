#include <bits/stdc++.h>
using namespace std;
#include "LinkList.cpp"
void deleteAlternateNodes(Node<int> *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given input itself.
     * No need to return pr print the output.
     * Taking input and printing output is handled automatically.
     */
    if( head == NULL || head -> next == NULL){
        return ;
    }
    head -> next = head -> next -> next;
    deleteAlternateNodes(head -> next);
}

int main() {
    Node<int> *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}