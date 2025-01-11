#include <bits/stdc++.h>;
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        //convert tree to undirected graph
        int maxVal=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            maxVal=max(maxVal,node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        vector<vector<int>>adjlist(maxVal+1);
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                adjlist[node->val].push_back(node->left->val);
                adjlist[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if(node->right){
                adjlist[node->val].push_back(node->right->val);
                adjlist[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }

        //perform bfs from start node
        int timer=0;
        vector<bool>infected(adjlist.size(),false);
        infected[start]=true;
        queue<int>que;
        que.push(start);

        while(!que.empty()){
            int size=que.size();
            bool spread=false;
            for(int i=0;i<size;i++){
                int node=que.front();
                que.pop();
                for(auto adjNode:adjlist[node]) {
                    if(!infected[adjNode]){
                        infected[adjNode]=true;
                        que.push(adjNode);
                        spread=true;//if at least one node is infected
                    }
                }
            }

            if(spread) timer++;
        }

        return timer;
    }
};