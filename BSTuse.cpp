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
//using namespace std;
class four
{
public:
    int height;
    int max;
    int min;
    bool isBst;
    four()
    {
        height = 0;
        max = 0;
        min = 0;
        isBst = true;
    }
};
four myans;
four helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        four ans;
        ans.height = 0;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        ans.isBst = true;
        return ans;
    }
    four leftans = helper(root->left);
    four rightans = helper(root->right);
    four ans;
    ans.height = 1 + max(leftans.height, rightans.height);
    ans.min = min(root->data, min(rightans.min, leftans.min));
    ans.max = max(root->data, max(leftans.max, rightans.max));
    ans.isBst = root->data > leftans.max && root->data <= rightans.min && leftans.isBst && rightans.isBst;
    if (ans.isBst)
    {
        if (ans.height > myans.height)
        {
            myans = ans;
        }
    }
    else
    {
        if (leftans.isBst)
        {
            if (leftans.height > myans.height)
            {
                myans = leftans;
            }
        }
        if (rightans.isBst)
        {
            if (rightans.height > myans.height)
            {
                myans = rightans;
            }
        }
    }
    return ans;
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here

    // if(root -> left == NULL&&root -> right == NULL){
    // return 1;
    // }
    // if(isBST(root)==true){
    // return height(root);
    // }
    // int leftans=largestBSTSubtree(root -> left);
    // int rightans=largestBSTSubtree(root -> right);
    helper(root);
    return myans.height;
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
BinaryTreeNode<int> *helper(int *input, int low, int n)
{
    if (low > n)
    {
        return NULL;
    }
    int mid = (low + n) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = helper(input, low, mid - 1);
    root->right = helper(input, mid + 1, n);
    return root;
}
BinaryTreeNode<int> *constructTree(int *input, int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return helper(input, 0, n - 1);
}
triplet isBst(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        triplet ans;
        ans.isBst = true;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        return ans;
    }
    triplet leftans = isBst(root->left);
    triplet rightans = isBst(root->right);

    triplet ans;
    ans.max = max(root->data, max(leftans.max, rightans.max));
    ans.min = min(root->data, min(leftans.min, rightans.min));

    ans.isBst = (root->data > leftans.max) && (root->data <= rightans.max) && (leftans.isBst) && (rightans.isBst);
    return ans;
}
void printAtLvlK(BinaryTreeNode<int>* root, int k)
{
    if(root == NULL)
    return;
    if(k<0){
        return ;
    }
    if(k==0)
    cout << root -> data << endl;

    printAtLvlK(root -> left , k-1);
    printAtLvlK(root -> right , k-1);

}
int nodesAtDistanceK2(BinaryTreeNode<int> *root, int node, int k)
{
    if (root == NULL)
        return -1;
    if (root->data == node)
    {
        printAtLvlK(root, k);
        return 0;
    }
    int ld = nodesAtDistanceK2(root->left, node, k);
    if (ld != -1)
    {
        if (ld + 1 == k)
            cout << root->data << endl;
            else{
        printAtLvlK(root->right, k - ld - 2);
            }
        return ld + 1;
    }
    int rd = nodesAtDistanceK2(root -> right, node, k);
    if(rd!=-1){
        if(rd+1)
        cout << root -> data << endl;
        else{
        printAtLvlK(root -> left , k- rd - 2);
        }
        return rd + 1;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    nodesAtDistanceK2(root, node, k);
}
int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
	   // Write your code here
  if(root == NULL){
      return -1;
  }
    if(root -> data == val1 || root -> data == val2){
        return root -> data;
    }
    int  leftans = lcaInBST(root -> left, val1, val2);
    int  rightans = lcaInBST(root -> right, val1, val2);
	
    if(leftans == -1 && rightans == -1 ){
        return -1;
    }
    else if(leftans!=-1&&rightans!=-1){
        return root -> data;
    }
    else if(leftans==-1&&rightans!=-1){
        return rightans;
    }else{
        return leftans;
    }
}

int main()
{

    int n;
    cin >> n;
}