#include <bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    bool searchHelper(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (root->data > data)
        {
            return searchHelper(data, node->left);
        }
        else
        {
            return searchHelper(data, node->right);
        }
    }

public:
    bool hasData(int data)
    {
        return searchHelper(data, root);
    }

private:
    void printHelper(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L" << node->left->data << ",";
        }
        if (node->right != NULL)
        {
            cout << "R" << node->right->data << ",";
        }
        printHelper(node->left);
        printHelper(node->right);
    }

public:
    void printTree()
    {
        printHelper(root);
    }

private:
    BinaryTreeNode<int> *insertHelper(int data, BinaryTreeNode<int> *node)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (node->data > data)
        {
            node->left = insertHelper(data, node->left);
        }
        else
        {
            node->right = insertHelper(data, node->right);
        }
        return node;
    }

private:
    
 
    BinaryTreeNode<int> *deleteDataHelper(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->data < data)
        {
            node -> left = deleteDataHelper(data, node -> left);
        }
         if else(node -> data > data)
        {
            node -> right = deleteDataHelper(data, node -> right);
        }
        else
        {
            if(node -> left == NULL && node -> right == NULL ){
                delete node;
            }else if(node-> left == NULL){
                  BinaryTreeNode<int>* temp = node -> right;
                  node -> right = NULL;
                  delete node;
                  return temp;
            }
            else if(node-> right == NULL){
                  BinaryTreeNode<int>* temp = node -> left;
                  node -> left = NULL;
                  delete node;
                  return temp;
            }else{
                BinaryTreeNode<int>* minNode = node -> right;
                while(minNode->left!=NULL){
                    minNode  = minNode -> left;
                }
                node -> data = minNode -> data
                node -> right = deleteDataHelper(minNode -> data,node -> right);
                return node;
            }

        }
        
        return node;
    }

public:
    void deleteData(int data)
    {
        root = deleteDataHelper(data, root);
    }

public:
    void insert(int data)
    {
        root = insertHelper(data, root);
    }
};