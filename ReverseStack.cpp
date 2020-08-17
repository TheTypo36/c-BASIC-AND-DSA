#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    // base case
    if (input.size() == 0 || input.size() == 1)
    {
        return; // as its reverse is same
    }
    // my work
    int n = input.top();
    input.pop();

    //indextion Hypothesis
    reverseStack(input, extra);
    //small calculation
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(n);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }

}

int main()
{
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        s1.push(val);
    }
    reverseStack(s1, s2);
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}
