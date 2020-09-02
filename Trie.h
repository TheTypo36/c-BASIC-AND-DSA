/*
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
*/
#include "TrieNode.h"
#include <string>

class Trie {
	TrieNode *root;

	public :

	Trie() {
		root = new TrieNode('\0');
	}

	bool search(TrieNode *root, string word) {
		if(word.size() == 0) {
			return root -> isTerminal;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return search(child, word.substr(1));
	}

	bool search(string word) {
		return search(root, word);
	}


	void insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		insertWord(child, word.substr(1));
	}

	// For user
	void insert(string word) {
		insertWord(root, word);
	}

	void removeWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = false;
			return;
		}

		// Small calculation
		TrieNode *child;
		int index =  word[0] - 'a';
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			// Word not found
			return;
		}

		removeWord(child, word.substr(1));

		// Remove child Node if it is useless
		if(child -> isTerminal == false) {
			for(int i = 0; i < 26; i++) {
				if(child -> children[i] != NULL) {
					return;
				}
			}
			delete child;
			root -> children[index] = NULL;
		}
	}









	void remove(string word) {
		removeWord(root, word);
	}














};
