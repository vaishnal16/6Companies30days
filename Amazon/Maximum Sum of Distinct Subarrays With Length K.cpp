#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0;
        long long sum=0;
        long long maxsum=0;
        unordered_map<int,int>mpp;
        while(right<n){
            mpp[nums[right]]++;
            sum+=nums[right];

            while(right-left+1>k || mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }

                sum-=nums[left];
                left++;
            }

            if(right-left+1==k && mpp.size()==k){
                maxsum=max(maxsum,sum);
            }

            right++;
        }

        return maxsum;
    }
};