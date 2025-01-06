#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sorting the envelops in asc order of width and des of height
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });

        vector<int>height;
        for(auto it:envelopes){
            height.push_back(it[1]);
        }

        //performing lis on height
        vector<int>lis;
        lis.push_back(height[0]);
        for(int i=1;i<height.size();i++){
            if(lis.back()<height[i]) lis.push_back(height[i]);
            else{
                //finding first elememt in lis which is greater than or equal to height[i]
                auto it=lower_bound(lis.begin(),lis.end(),height[i]);
                *it=height[i];
            }
        }

        return lis.size();
    }
};