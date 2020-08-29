#include <bits/stdc++.h>
using namespace std;
#include "OurMap.h"

int main()
{
    OurMap<int> freq;
  for (int i = 0; i < 10; i++)
  {
      char ch = '0' + i;
      string key = "abc";
      key = key + ch;
      int value = i+1;
    freq.insert(key,value);
    cout <<"LoadFactor " << freq.getLoadFactor() << endl;
  }
  cout <<"size: "<< freq.getSize() << endl;
    cout <<"removed values: " << freq.remove("abc5") << endl;
    cout <<"removed values: " << freq.remove("abc9") << endl;

  for (int i = 0; i < 10; i++)
  {
      char ch = '0' + i;
      string key = "abc";
      key = key + ch;
    cout << key << ": " << freq.getValue(key) << endl;
  }
  cout <<"size: "<< freq.getSize() << endl;

  
}