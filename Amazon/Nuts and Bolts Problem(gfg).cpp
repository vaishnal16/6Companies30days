#include <bits/stdc++.h>;
using namespace std;

class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        vector<char>order={'!','#','$','%','&','*','?','@','^'};
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nuts[i]]++;
        }
        
        vector<int>temp;
        for(int i=0;i<9;i++){
            char ch=order[i];
            if(mpp.find(ch)!=mpp.end()){
                temp.push_back(ch);
            }
        }
        
        for(int i=0;i<n;i++){
            nuts[i]=temp[i];
            bolts[i]=temp[i];
        }
        
    }
};