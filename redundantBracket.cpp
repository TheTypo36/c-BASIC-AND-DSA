#include <bits/stdc++.h>
using namespace std;
bool checkRedundantBrackets(char *input)
{
    // Write your code here
    stack<char> s;
    int i = 0;
    while (input[i] != '\0')
    {
        int count = 0;
        if (input[i] = ')')
        {

            while (s.top() != '(')
            {
                s.pop();
                count++;
            }
            s.pop();
            if (count == 0)
            {
                return true;
            }
        }
        else
        {
            s.push(input[i]);
        }

        i++;
    }
    return false;
}
int main()
{
}
