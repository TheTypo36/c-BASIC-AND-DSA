#include <bits/stdc++.h>
using namespace std;
vector<int> kLargest(int *input, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> kelements;
    for (int i = 0; i < k; i++)
    {
        kelements.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        kelements.push(input[i]);
        kelements.pop();
    }
    vector<int> ans;
    while (!kelements.empty())
    {
        ans.push_back(kelements.top());
        kelements.pop();
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
    vector<int> ans = kLargest(arr, n, k);
    int i = 0;
    while (i < ans.size())
    {
        /* code */
        cout << ans[i] << endl;
        i++;
    }
}