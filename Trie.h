#include "TrieNode.h"
#include <string>
using namespace std;

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insert(string word, TrieNode *node)
    {
        if (word.length() == 0)
        {
            node->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child = NULL;
        if (node->children[index] != NULL)
        {
            child = node->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }
        insert(word.substr(1), child);
    }
    void insert(string word)
    {
        insert(word, root);
    }
    bool search(string word, TrieNode *node)
    {
        
       if(word.length()==0){
           
                return node->isTerminal;
        
        }
        int index = word[0] - 'a';
        if(node -> children[index] == NULL)
        {
            return false;
        }
       TrieNode* child = node -> children[index];
           return search(word.substr(1), child);
        
    }
    bool search(string word)
    {
        return search(word, root);
    }
    void remove(string word, TrieNode *node)
    {
        if (word.length() == 0)
        {
            node -> isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child = NULL;
        if(node -> children[index] == NULL){
            return ;
        }else{
            child = node -> children[index];
        }
        remove(word.substr(1),child);
        if(child->isTerminal==false){
            for(int i = 0 ; i < 26; i++){
                if(child->children[i]!=NULL){
                    return;
                }

            }
            delete child;
           node -> children[index] = NULL;
        }
    }
    void remove(string word)
    {
        remove(word, root);
    }
};




