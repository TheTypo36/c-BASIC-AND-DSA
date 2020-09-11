#include <bits/stdc++.h>
using namespace std;

int knapsackDp(int* weight,int* value,int n, int maxWeight){
       int** strg = new int*[n+1];
    for (int i = 0; i <=n ; i++)
    {
        strg[i] = new int[maxWeight+1];        
    }
    for (int i = 0; i < n+1; i++)
    {
        strg[i][0] = 0;
    }
    for (int i = 0; i < maxWeight+1; i++)
    {
        strg[0][i] = 0;
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < maxWeight+1; j++)
        {
            if(weight[i-1]<=j){
                strg[i][j] = max(value[i-1]+strg[i-1][j-weight[i-1]],strg[i-1][j]);
            }else{
                strg[i][j] = strg[i-1][j];
            }
        }
        
    }
    return strg[n][maxWeight];
    
    
}
int knapsackMemoization(int* weight, int* values,int n, int maxWeight,int** strg){
    if(n==0||maxWeight==0){
        return  0;
    }
    if(strg[n][maxWeight]!=-1)
    {
        return strg[n][maxWeight];
    }
    int ans;
    if(maxWeight<weight[0]){
        ans = knapsackMemoization(weight+1,values+1,n-1,maxWeight,strg);
    }else{
        int r = knapsackMemoization(weight+1,values+1,n-1,maxWeight,strg);
        int r1 = knapsackMemoization(weight+1,values+1,n-1,maxWeight-weight[0],strg)+values[0];
        ans = max(r,r1);
    }
    strg[n][maxWeight] = ans;
    return ans;
}
int knapsack(int* weights,int* values, int n ,int maxWeight){
    if(n == 0|| maxWeight == 0){
        return 0;
    }
    if(maxWeight<weights[0]){
        return knapsack(weights+1,values+1,n-1,maxWeight);
    }
    

        int recur = knapsack(weights+1,values+1,n-1,maxWeight);
        int recur2 = values[0] + knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
    	int ans=max(recur,recur2);
    
    return ans;
  
}
int main() {
	int n; 
	cin >> n;
    
	int maxWeight;
	cin >> maxWeight;

	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

    int** strg = new int*[n+1];
    for (int i = 0; i <=n ; i++)
    {
        strg[i] = new int[maxWeight+1];
        for (int j = 0; j <=maxWeight; j++)
        {
            strg[i][j] = -1;
        }
        
    }
    cout << "Dynamic Programming Approach: " << knapsackDp(weights,values,n,maxWeight) << endl;
    cout << "Memoization Approach: " << knapsackMemoization(weights,values,n,maxWeight,strg) << endl; 
	cout << "Recursive Approach: "<< knapsack(weights, values, n, maxWeight) << endl;
}