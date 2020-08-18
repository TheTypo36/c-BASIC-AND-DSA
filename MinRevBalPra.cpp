#include <bits/stdc++.h>
using namespace std;
int countBracketReversals(char input[])
{
    int l = strlen(input);
    if (l % 2 != 0)
    {
        return -1;
    }
    stack<char> s;
    int i = 0, c = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '{')
        {
            s.push(input[i]);
        }
        else if (input[i] == '}' && !s.empty() && s.top() == '{')
        {
            s.pop();
        }
        else if (input[i] == '}' && s.empty())
        {
            s.push(input[i]);
        }
        else if ((input[i] == '}' && !s.empty()) && s.top() != '{')
        {
            s.push('}');
        }
        i++;
    }
    int c1 = 0, c2 = 0;
    while (!s.empty())
    {
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();
        if (c1 == c2)
        {
            c++;
        }
        else
        {
            c += 2;
        }
        // s.pop();
    }

    return c;
}
int main()
{
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}