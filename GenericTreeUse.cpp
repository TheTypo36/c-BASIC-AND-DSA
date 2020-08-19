#include <bits/stdc++.h>
#include "TreeNode.h"
TreeNode<int> *takeInput()
{
    cout << "Enter the data: " << endl;
    int rootData =0;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    cout << "enter the number of child of " << rootData << endl;
    int noOfchildren = 0;
    cin >> noOfchildren;
    for(int i = 0 ; i < noOfchildren; i++){
        TreeNode<int> * child = takeInput();
        root -> children.push_back(child);
    }
    return root;

}
void print(TreeNode<int>* root){
    if(root == NULL){
        return ;
    }
    cout << root -> data << ": " ;
    for (int i = 0; i < root -> children.size(); i++)
    {
        cout << root -> children[i] -> data<<"," ;
    }
    cout << endl;
    for (int i = 0; i < root -> children.size(); i++)
    {
    print(root -> children[i]);
        /* code */
    }
    
    
}
int main()
{
    TreeNode<int> *root = takeInput();
    print(root);
}
// 1 3 2 2 6 0 7 0 3 1 8 0 4 1 9 0