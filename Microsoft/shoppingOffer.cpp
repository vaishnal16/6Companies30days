#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string,int>dp;//store needs as string ,corresponding result
        return helper_function(price,special,needs,dp);
    }

    private:
    int helper_function(vector<int>& price,vector<vector<int>>& special,vector<int>& needs,unordered_map<string,int>& dp){

        string key=serialize(needs);
        if(dp.count(key)) return dp[key]; 

        int j=0,res=calculate_cost(price,needs);

        for(auto& s:special){
            vector<int>temp=needs;
            for(j=0;j<needs.size();j++){
                int diff=temp[j]-s[j];
                if(diff<0) break;
                temp[j]=diff;
            }
            if(j==needs.size()){
                res=min(res,s[j]+helper_function(price,special,temp,dp));
            }
        }
        return dp[key]=res;
    }

    int calculate_cost(vector<int>& price,vector<int>& needs){
        int cost=0;
        for(int i=0;i<price.size();i++){
            cost+=needs[i]*price[i];
        }
        return cost;
    }

    string serialize(vector<int>& needs){
        string key="";
        for(int i=0;i<needs.size();i++){
            key+=to_string(needs[i])+",";
        }
        return key;
    }
};