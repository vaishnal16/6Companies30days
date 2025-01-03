#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int>arr;
                for(int k=0;k<n;k++){
                    if(k>=i && k<=j) continue;
                    else arr.push_back(nums[k]);
                }
                if(isIncreasing(arr)) count++;
            }
        }
        return count;
    }

    private:
    bool isIncreasing(vector<int>& arr){
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]) return false;
        }
        return true;
    }
};