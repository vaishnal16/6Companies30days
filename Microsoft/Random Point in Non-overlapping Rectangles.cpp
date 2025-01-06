#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<int>v;
    vector<vector<int>>rect;

    //calculating total integral points in rectangle
    int area(vector<int>& r){
        return (r[2]-r[0]+1)*(r[3]-r[1]+1);
    }

    Solution(vector<vector<int>>& rects) {
        rect=rects;
        int totalArea=0;
        for(auto it:rect){
            totalArea+=area(it);//calculating total integral points for all rectangles
            v.push_back(totalArea);
        }
    }
    
    vector<int> pick() {
        //pick random rectangle
        int random=rand()%v.back();
        int index=upper_bound(v.begin(),v.end(),random)-v.begin();

        //pick random point in rect[index]
        auto r=rect[index];
        int x=rand()%(r[2]-r[0]+1)+r[0];
        int y=rand()%(r[3]-r[1]+1)+r[1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */