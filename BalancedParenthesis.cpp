#include <bits/stdc++.h>
using namespace std;
bool checkBalanced(char *exp)
{
    stack<int> s;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (s.empty())
            {
                return false;
            }
            else if (exp[i] =='}' &&s.top()=='{')
            {
                s.pop();
            }
             else if (exp[i] ==']' &&s.top()=='[')
            {
                s.pop();
            }
             else if (exp[i] ==')' &&s.top()=='(')
            {
                s.pop();
            }
            
            else
            {
                return false;
            }
        }
        i++;
    }
    return s.empty();
}
int main()
{
    char input[100000];
    cin.getline(input, 100000);
    //    cin >> input;
    if (checkBalanced(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}