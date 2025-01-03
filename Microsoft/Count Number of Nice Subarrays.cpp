#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //treat odd no=1 , even no-0
        int ans=find_nice_subarrays(nums,k)-find_nice_subarrays(nums,k-1);
        return ans;
    }

    int find_nice_subarrays(vector<int>& arr,int goal){
        int left=0,right=0;
        int sum=0,cnt=0;
        if(goal<0) return 0;
        while(right<arr.size()){
            if(arr[right]%2==1) sum+=1;
            while(sum>goal){
                if(arr[left]%2==1) sum-=1;
                left++;
            }
            cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
};