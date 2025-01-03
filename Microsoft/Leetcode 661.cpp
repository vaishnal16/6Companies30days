#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        vector<pair<int,int>>neighbour={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=1;
                float avg=img[i][j];
                for(int k=0;k<8;k++){
                    auto it=neighbour[k];
                    int nrow=it.first,ncol=it.second;
                    int adjrow=i+nrow;
                    int adjcol=j+ncol;
                    if(adjrow>=0 && adjrow<n && adjcol>=0 && adjcol<m){
                        avg+=img[adjrow][adjcol];
                        count++;
                    }
                }
                avg=floor(avg/count);
                ans[i][j]=avg;
            }
        }
        return ans;
    }
};