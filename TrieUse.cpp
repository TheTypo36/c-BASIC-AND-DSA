#include "Trie.h"
using namespace std;

int main()
{
    Trie t;
   t.insert("ashish");
    t.insert("anand");
    t.insert("ayush");

    cout << t.search("ashish") << endl;
    cout << t.search("anand") << endl;
    cout << t.search("ayush") << endl;
    cout << "*******************" << endl;
    remove("ashish");
    cout << t.search("ayush") << endl;
    cout << t.search("ashish") << endl;
    cout << t.search("anand") << endl;
}