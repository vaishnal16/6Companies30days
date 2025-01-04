#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        string s1="",s2="";
        int result=0;
        dfs(s,0,s1,s2,result);
        return result;
    }

    private:
    bool isPalindrome(string& s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }

    void dfs(string& s,int index,string& s1,string& s2,int& result){
        if(index>=s.size()){
            if(isPalindrome(s1) && isPalindrome(s2)) result=max(result,(int)s1.size()*(int)s2.size());
            return ;
        }

        //first take it in s1 then s2 and then do not take it in both

        s1.push_back(s[index]);
        dfs(s,index+1,s1,s2,result);
        s1.pop_back();//back-tracking

        s2.push_back(s[index]);
        dfs(s,index+1,s1,s2,result);
        s2.pop_back();

        dfs(s,index+1,s1,s2,result);
    }
};