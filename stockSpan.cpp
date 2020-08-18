#include <bits/stdc++.h>
using namespace std;

int *stockSpan(int *arr, int size)
{
    int *ans = new int[size];
    ans[0] = 1;
    stack<int> s;
    s.push(0);

    for (int i = 1; i < size; i++)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - s.top();
        }
        s.push(i);
    }
    return ans;
}
int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }
}
