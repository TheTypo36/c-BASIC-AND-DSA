#include <bits/stdc++.h>
using namespace std;


void kSortedArray(int* arr,int n,int k)
 {
     priority_queue<int> kMax ;
     int j = 0;
     for (int i = 0; i < n; i++)
     {
         if(i>=k){
             arr[j] = kMax.top();
             kMax.pop();
             kMax.push(arr[i]);
             j++;
         }else{
             kMax.push(arr[i]);
         }
     }
     while(k--){
         arr[j] = kMax.top();
             kMax.pop();
           //  kMax.push(arr[i]);
             j++;
     }
     
 }
int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int  i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    
    int k;
    cin >> k ;
    kSortedArray(arr,n,k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}