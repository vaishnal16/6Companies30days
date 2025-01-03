#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int middle=nums[n/2];
        int op=0;

        for(int i=0;i<n;i++){
            op+=abs(nums[i]-middle);
        }

        return op;
    }
};