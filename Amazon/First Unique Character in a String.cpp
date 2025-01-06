#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            int first_ocurr=s.find(s[i]);
            int last_ocurr=s.rfind(s[i]);
            if(first_ocurr==last_ocurr) return i;
        }
        return -1;
    }
};