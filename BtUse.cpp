#include <bits/stdc++.h>
using namespace std;
#include "Node.cpp";
#include "BinaryTreeNode.h"
void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ':';
    if (root->left != NULL)
    {
        cout << 'L' << root->left->data << ',';
    }
    if (root->right != NULL)
    {
        cout << 'R' << root->right->data;
    }
    cout << endl;

    print(root->left);
    print(root->right);
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
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }
    BinaryTreeNode<int> *t = root->left;
    root->left = root->right;
    root->right = t;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
pair<int, int> helper1(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    pair<int, int> leftAns = helper1(root->left);
    pair<int, int> rightAns = helper1(root->right);
    pair<int, int> ans;
    ans.first = 1 + max(leftAns.first, rightAns.first);
    int option = leftAns.first + rightAns.first;
    int option2 = leftAns.second;
    int option3 = rightAns.second;

    ans.second = max(option, max(option2, option3));
    return ans;
}
int diameter(BinaryTreeNode<int> *root)
{
    return helper1(root).second;
}
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
void nodesWithoutSibling(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }
    if ((root->left == NULL && root->right != NULL))
    {
        cout << root->right->data << endl;
    }
    if (root->right == NULL && root->left != NULL)
    {
        cout << root->left->data << endl;
    }
    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
}
pair<int, int> magicNodeHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    if (root->left == NULL || root->right == NULL)
    {
        pair<int, int> ans;
        ans.first = root->data;
        ans.second = 0;
        return ans;
    }
    pair<int, int> leftAns = magicNodeHelper(root->left);
    pair<int, int> rightAns = magicNodeHelper(root->right);
    pair<int, int> ans;
    ans.first = root->data + leftAns.first + rightAns.first;
    if (leftAns.first % 2 == 0 && rightAns.first % 2 != 0)
    {
        ans.second = leftAns.second + rightAns.second + root->data;
    }
    else if (leftAns.first % 2 != 0 && rightAns.first % 2 == 0)
    {
        ans.second = leftAns.second + rightAns.second + root->data;
    }else{
        ans.second = leftAns.second + rightAns.second;
    }
    return ans;
}
int magicNodeSum(BinaryTreeNode<int> *root)
{
    return magicNodeHelper(root).second;
}
vector<Node<int> *> createLLForEachLevel(BinaryTreeNode<int> *root)
{

    vector<Node<int> *> ans;

    queue<BinaryTreeNode<int> *> q;
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front == NULL)
        {

            ans.push_back(head);
            head = NULL;
            tail = NULL;
            if (q.empty())
            {
                break;
            }
            q.push(NULL);
        }
        else
        {
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
            Node<int> *newNode = new Node<int>(front->data);
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
        }
    }
    return ans;
}

BinaryTreeNode<int> *takeInput()
{
    int n;
    cout << "Enter the data" << endl;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *rootNode = new BinaryTreeNode<int>(n);
    BinaryTreeNode<int> *leftNode = takeInput();
    BinaryTreeNode<int> *righttNode = takeInput();

    rootNode->left = leftNode;
    rootNode->right = righttNode;
    return rootNode;
}
pair<int, bool> helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, bool> ans;
        ans.first = 0;
        ans.second = true;
        return ans;
    }
    pair<int, bool> left = helper(root->left);
    pair<int, bool> right = helper(root->right);

    pair<int, bool> ans;
    ans.first = 1 + max(left.first, right.first);
    int a = min(left.first, right.first);
    int b = max(left.first, right.first);
    int min = b - a;
    if (min <= 1 && left.second == true && right.second == true)
    {
        ans.second = true;
    }
    else
    {
        ans.second = false;
    }
    return ans;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    return helper(root).second;
}

int main()
{

    BinaryTreeNode<int> *root = takeInputLevelWise();
    print(root);
    cout << "sum: "<<magicNodeHelper(root).first << endl;
    cout << "sum of magic node: "<<magicNodeHelper(root).second << endl;

    delete root;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 7 8 -1 9 10 -1 -1 -1 -1
//  12 17 16 -1 -1 4 9 2 3 -1 -1  -1 -1 -1 -1