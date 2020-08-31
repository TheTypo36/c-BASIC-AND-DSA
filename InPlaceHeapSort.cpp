#include <bits/stdc++.h>
using namespace std;
void heapSort(int *input, int size)
{
    for (int i = 1; i < size; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (i - 1) / 2;
            if (input[childIndex] < input[parentIndex])
            {
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
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
        heapSort(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr;
    }