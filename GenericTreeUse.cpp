#include <bits/stdc++.h>
#include "TreeNode.h"
TreeNode<int> *takeInput()
{
    cout << "Enter the data: " << endl;
    int rootData = 0;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    cout << "enter the number of child of " << rootData << endl;
    int noOfchildren = 0;
    cin >> noOfchildren;
    for (int i = 0; i < noOfchildren; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
        /* code */
    }
}
void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pending_Nodes;
    pending_Nodes.push(root);
    while (!pending_Nodes.empty())
    {
        TreeNode<int> *f = pending_Nodes.front();
        pending_Nodes.pop();
        cout << f->data << ":";

        for (int i = 0; i < f->children.size(); i++)
        {
            if (i == f->children.size() - 1)
            {
                cout << f->children[i]->data;
            }
            else
            {
                cout << f->children[i]->data << ",";
            }
        }
        cout << endl;

        for (int j = 0; j < f->children.size(); j++)
        {
            pending_Nodes.push(f->children[j]);
        }
    }
}
int nodesGreaterThanX(TreeNode<int> *root, int x)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if (root == NULL)
    {
        return 0;
    }

    int ans = 0;
    if (root->data > x)
    {
        ans = 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += nodesGreaterThanX(root->children[i], x);
    }
    return ans;
}
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    int maxSum = root->data;
    TreeNode<int> *ans = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxSum += root->children[i]->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = maxSumNode(root->children[i]);
        int smallData = smallAns->data;
        for (int i = 0; i < smallAns->children.size(); i++)
        {
            smallData += smallAns->children[i]->data;
        }
        if (maxSum < smallData)
        {
            ans = smallAns;
            maxSum = smallData;
        }
    }

    return ans;
}
int countNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int smallAns = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        smallAns += countNode(root->children[i]);
    }
    return smallAns + 1;
}
int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}
int height(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = max(ans, height(root->children[i]));
    }
    return ans + 1;
}
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode<int> *ans = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *recurans = maxDataNode(root->children[i]);
        if (recurans->data > ans->data)
        {
            ans = recurans;
        }
        else
        {
            ans = ans;
        }
    }
    return ans;
}
void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}
bool containsX(TreeNode<int> *root, int x)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
    */
    if (root->data == x)
    {
        return true;
    }
    bool smallans = false;
    for (int i = 0; i < root->children.size(); i++)
    {
        smallans = containsX(root->children[i], x);
        if (smallans)
            return true;
    }
    return smallans;
}
TreeNode<int> *takeInputLevelWise()
{
    cout << "Enter the root data" << endl;
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pending_Nodes;
    pending_Nodes.push(root);
    while (!pending_Nodes.empty())
    {
        TreeNode<int> *f = pending_Nodes.front();
        pending_Nodes.pop();
        cout << "how many children do " << f->data << " have: " << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter the data of " << i << "th child of node " << f->data << endl;
            int childData = 0;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            f->children.push_back(child);
            pending_Nodes.push(child);
        }
        delete root;
    }
    return root;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << countNode(root) << endl;
}
// 1 3 2 2 6 0 7 0 3 1 8 0 4 1 9 0
//1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0