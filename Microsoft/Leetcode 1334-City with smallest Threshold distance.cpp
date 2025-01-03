#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adjlist(n);
        for(auto edge:edges){
            int node1=edge[0],node2=edge[1];
            int weight=edge[2];
            adjlist[node1].push_back({node2,weight});
            adjlist[node2].push_back({node1,weight});
        }

        vector<vector<int>>shortestPathMatrix(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            shortestPathMatrix[i][i]=0;
        }

        for(int i=0;i<n;i++){
            dijkstra(n,adjlist,shortestPathMatrix[i],i);
        }

        return cityWithFewestReachable(n,shortestPathMatrix,distanceThreshold);
    }

    private:
    void dijkstra(int n,vector<vector<pair<int,int>>>& adjlist,vector<int>& shortestPath,int source){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//dist,source
        pq.push({0,source});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int currentDistance=it.first;
            int currentCity=it.second;

            if(currentDistance>shortestPath[currentCity]) continue;

            for(auto it:adjlist[currentCity]){
                int adjNode=it.first;
                int edge=it.second;

                if(currentDistance+edge<shortestPath[adjNode]){
                    shortestPath[adjNode]=currentDistance+edge;
                    pq.push({edge+currentDistance,adjNode});
                }
            }
        }
    }


    int cityWithFewestReachable(int n,const vector<vector<int>>& shortestPathMatrix,int distanceThreshold){


        int ans=-1;
        int fewest_counter=n;

        for(int i=0;i<n;i++){
            int counter=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;

                if(shortestPathMatrix[i][j]<=distanceThreshold){
                    counter++;
                }
            }

            if(counter<fewest_counter ||counter==fewest_counter && i > ans){
                fewest_counter=counter;
                ans=i;
            }
        }

        return ans;
    }
};