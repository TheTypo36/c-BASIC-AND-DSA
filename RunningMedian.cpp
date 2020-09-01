#include <bits/stdc++.h>
using namespace std;

void findMedian(int arr[], int n)
{
    priority_queue<double> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    cout << arr[0] << endl;
    maxh.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (maxh.top() < arr[i])
        {
            minh.push(arr[i]);
        }
        else
        {
            maxh.push(arr[i]);
        }
        int diff = 0;
        if (maxh.size() > minh.size())
        {
            diff = maxh.size() - minh.size();
        }
        else
        {
            diff = minh.size() - maxh.size();
        }
        if (diff > 1)
        {
            if (maxh.size() > minh.size())
            {
                minh.push(maxh.top());
                maxh.pop();
            }
            else
            {
                maxh.push(minh.top());
                minh.pop();
            }
        }
        if ((i + 1) % 2 == 0)
        {
            int larg = maxh.top();
            int smal = minh.top();
            int avg = (larg + smal) / 2;
            cout << avg << endl;
        }
        else
        {
            if (maxh.size() > minh.size())
            {
                cout << maxh.top() << endl;
            }
            else
            {
                cout << minh.top() << endl;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;

    int arr[n], i;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    findMedian(arr, n);
}