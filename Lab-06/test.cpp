#include<bits/stdc++.h>
using namespace std;

int knapsack(int W,int n,vector<int>& weights,vector<int>&profits){
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(weights[i-1] <= w){
                dp[i][w] = max(profits[i-1] + dp[i-1][w-weights[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main(){
   int W,n;
   cin>> W;
   cin>>n;

   vector<int>weights(n);
   vector<int>profits(n);

   for(int i=0;i<n;i++){
    cin>> weights[i];
   }
   for(int i=0;i<n;i++){
    cin>>profits[i];
   }

   int maxValue = knapsack(W,n,weights,profits);
   cout<<maxValue<<endl;

   return 0;
}
