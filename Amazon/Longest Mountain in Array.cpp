#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return 0;
        int ans = 0;
        int base = 0;
        while (base < n) {
            int end = base;
            // findig the peak
            if (end + 1 < n && arr[end + 1] > arr[end]) {
                while (end + 1 < n && arr[end + 1] > arr[end])
                    end++;
                // finding the lowest point if current end is really peak
                if (end + 1 < n && arr[end + 1] < arr[end]) {
                    while (end + 1 < n && arr[end + 1] < arr[end])
                        end++;
                    ans = max(ans, end - base + 1);
                }
            }

            base = max(end, base + 1); // if we can not find mountain from that
                                       // index go to base+1
        }

        return ans;
    }
};