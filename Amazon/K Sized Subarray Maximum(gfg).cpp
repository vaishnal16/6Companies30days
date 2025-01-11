#include <bits/stdc++.h>;
using namespace std;

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int,int>>pq;
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<k;i++){
            pq.push({arr[i],i});
        }
        ans.push_back(pq.top().first);
        
        for(int i=k;i<n;i++){
            pq.push({arr[i],i});
            
            while(pq.top().second<=i-k){
                pq.pop();
            }
            
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};