#include <bits/stdc++.h>;
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node*temp=head;
        
        while(temp!=nullptr){
            //skip m nodes
            for(int i=1;i<m && temp!=nullptr;i++){
                temp=temp->next;
            }
            
            if(temp==nullptr) break;
            
            Node*todelete=temp->next;
            //start deleting n nodes
            for(int i=0;i<n && todelete!=nullptr;i++){
                Node*nextNode=todelete->next;
                delete todelete;
                todelete=nextNode;
            }
            
            temp->next=todelete;
            temp=todelete;
        }
        return head;
    }
};