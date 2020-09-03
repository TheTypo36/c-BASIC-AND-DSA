#include <bits/stdc++.h>
using namespace std;
int countSeptsToOneDP(int n)
{
    int *strg = new int[n + 1];
    //seeding
    strg[0] = 0;
    strg[1] = 0;
    strg[2] = 1;
    strg[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        int f1 = 1 + strg[i - 1];
        if (i % 2 == 0)
        {
            int f2 = 1 + strg[i / 2];
            f1 = min(f1, f2);
        }
        if (i % 3 == 0)
        {
            int f3 = 1 + strg[i / 3];
            f1 = min(f1, f3);
        }
        strg[i] = f1;
    }
    return strg[n];
}
int countSeptsToOneMemoization(int n, int *strg)
{
    if (n <= 1)
    {
        return 0;
    }
    if (strg[n] != -1)
    {
        return strg[n];
    }
    int f1 = 1 + countSeptsToOneMemoization(n - 1, strg);
    //int f2=0, f3=0;
    if (n % 2 == 0)
    {
        int f2 = 1 + countSeptsToOneMemoization(n / 2, strg);
        f1 = min(f1, f2);
    }
    if (n % 3 == 0)
    {
        int f3 = 1 + countSeptsToOneMemoization(n / 3, strg);
        f1 = min(f1, f3);
    }
    strg[n] = f1;
    return strg[n];
}
int countStepsTo1(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    int f1 = 1 + countStepsTo1(n - 1);
    //int f2=0, f3=0;
    if (n % 2 == 0)
    {
        int f2 = 1 + countStepsTo1(n / 2);
        f1 = min(f1, f2);
    }
    if (n % 3 == 0)
    {
        int f3 = 1 + countStepsTo1(n / 3);
        f1 = min(f1, f3);
    }
    return f1;
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    cout << "Dynamic Programming Approach: " << countSeptsToOneDP(n) << endl;
    cout << "Memoization Approach: " << countSeptsToOneMemoization(n, arr) << endl;
    cout << "Recursive Approach: " << countStepsTo1(n) << endl;
}