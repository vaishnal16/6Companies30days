#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
const int alphabets=26;
const int INF=1e9;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        vector<vector<int>>graph(alphabets,vector<int>(alphabets,INF));

        for(int i=0;i<alphabets;i++){
            graph[i][i]=0;
        }

        for(int i=0;i<original.size();i++){
            int u=original[i]-'a',v=changed[i]-'a';
            graph[u][v]=min(graph[u][v],cost[i]);
        }

        //floyd-worshall
        for(int k=0;k<alphabets;k++){
            for(int i=0;i<alphabets;i++){
                for(int j=0;j<alphabets;j++){
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }

        long long minCost=0;
        for(int i=0;i<source.size();i++){
            int u=source[i]-'a',v=target[i]-'a';
            if(graph[u][v]==INF) return -1;
            else minCost+=graph[u][v];
        }
        return minCost;
    }
};