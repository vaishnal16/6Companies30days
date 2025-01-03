#include <bits/stdc++.h>;
using namespace std;

#include <bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>friends;
        for(int i=1;i<=n;i++){
            friends.push_back(i);
        }

        int currIndex=0;
        while(friends.size()>1){
            currIndex=(currIndex+k-1)%friends.size();
            friends.erase(friends.begin()+currIndex);
        }

        return friends[0];
    }
};

//Optimized approch of this quetion
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // 0-based index
        for (int i = 2; i <= n; i++) {
            winner = (winner + k) % i;
        }
        return winner + 1; // Convert to 1-based index
    }
};
