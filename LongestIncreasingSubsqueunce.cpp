#include <bits/stdc++.h>
using namespace std;
 int lis(int *arr,int n){
    int *output = new int[n];
    
    int t = 0;
     for(int i=0;i<n;i++){
         output[i]=0;
     }
     output[0] = 1;
   // output[1] = 1;
    for (int i = 1; i < n; i++)
    {
        int j = i-1; 
        int maxi = 0;
        while (j>=0)
        {
            if(arr[i]>arr[j]){
                maxi = max(maxi,output[j]);
            }
            j--;
        }
        output[i] = maxi+1;
        if(t<output[i])
        t = output[i];
        
    }
    return t;
}
int main(){

      int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << lis(arr, n) << endl;
}