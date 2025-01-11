#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return function(0,1,k,prices,n,dp);
    }

    int function(int index,int buy,int counter,vector<int>& prices,int n,vector<vector<vector<int>>>& dp){
        if(index==n||counter==0) return 0;

        if(dp[index][buy][counter]!=-1) return dp[index][buy][counter];  
        int profit=0;
        if(buy){
            int buyStock=-prices[index]+function(index+1,0,counter,prices,n,dp);
            int notbuystock=0+function(index+1,1,counter,prices,n,dp);
            profit=max(buyStock,notbuystock);
        }
        else{
            int sellStock=prices[index]+function(index+1,1,counter-1,prices,n,dp);
            int notsellstock=0+function(index+1,0,counter,prices,n,dp);
            profit=max(sellStock,notsellstock);
        }

        return dp[index][buy][counter]=profit;
    }
};