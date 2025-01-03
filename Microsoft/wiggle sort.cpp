#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>sorted=nums;
        int n=nums.size();
        sort(sorted.begin(),sorted.end());

        int low=(n-1)/2;//middle index for smaller half
        int high=n-1;//end index for larger half 

        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=sorted[low--];//place in reverse order
            }
            else{
                nums[i]=sorted[high--];//place in reverse order 
            }
        }
    }
};