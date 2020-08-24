#include <bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"
#include "triplet.h"
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {

        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        else
        {
            cout << "L:" << -1 << ",";
        }
        if (front->right != NULL)
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << "R:" << -1;
        }
        cout << endl;
    }
}
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter the root Data: " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pending_nodes.front();
        pending_nodes.pop();

        cout << "Enter left node Data of node " << front->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *Child = new BinaryTreeNode<int>(leftData);
            front->left = Child;
            pending_nodes.push(Child);
        }

        cout << "Enter right node Data of node " << front->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *Child = new BinaryTreeNode<int>(rightData);
            front->right = Child;
            pending_nodes.push(Child);
        }
    }
    return root;
}
BinaryTreeNode<int>* helper(int *input,int low, int n){
    if(low>n){
        return NULL;
    }
    int mid = (low+n)/2;
        BinaryTreeNode<int>* root =new BinaryTreeNode<int>(input[mid]);
    root -> left = helper(input,low,mid-1);
    root -> right = helper(input,mid+1,n);
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	    return helper(input,0,n-1);
}
triplet isBst(BinaryTreeNode<int> * root){
    if(root == NULL){
        triplet ans;
        ans.isBst = true;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        return ans;
    }
    triplet leftans = isBst(root -> left);
    triplet rightans = isBst(root -> right);
    
    triplet ans;
    ans.max = max(root->data, max(leftans.max,rightans.max));
    ans.min = min(root->data,min(leftans.min,rightans.min));

    ans.isBst = (root -> data > leftans.max) && (root -> data <= rightans.max)  && (leftans.isBst) && (rightans.isBst);
    return ans;
}
int main(){

    int n;
   cin >> n;

}