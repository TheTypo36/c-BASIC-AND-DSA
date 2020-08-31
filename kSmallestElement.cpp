#include <bits/stdc++.h>
using namespace std;
vector<int> kSmallest(int *input, int n, int k)
{
    // Write your code here

    priority_queue<int> kS;
    for (int i = 0; i < k; i++)
    {
        kS.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        kS.push(input[i]);
        kS.pop();
    }

    vector<int> ans;
    while (!kS.empty())
    {
        ans.push_back(kS.top());
        kS.pop();
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vector<int> ans = kSmallest(arr, n, k);
    int i = 0;
    while (i<ans.size())
    {
        /* code */
        cout << ans[i] << endl;
        i++;
    }
}