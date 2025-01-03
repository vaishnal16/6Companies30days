//bulls and cows 
#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        unordered_map<char,int>mpp;
        int cows=0,bulls=0;

        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) bulls++;
            else{
                mpp[secret[i]]++;
            }
        }

        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i] && mpp[guess[i]]>0){
                cows++;
                mpp[guess[i]]--;
            }
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};