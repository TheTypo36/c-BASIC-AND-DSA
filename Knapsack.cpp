#include <bits/stdc++.h>
using namespace std;

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
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

    int** strg = new int*[n+1];
    for (int i = 0; i <=n ; i++)
    {
        strg[i] = new int[maxWeight+1];
        for (int j = 0; j <=maxWeight; j++)
        {
            strg[i][j] = -1;
        }
        
    }
    cout << "Memoization Approach: " << knapsackMemoization(weights,values,n,maxWeight,strg) << endl; 
	cout << "Recursive Approach: "<< knapsack(weights, values, n, maxWeight) << endl;
}