#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    
    Node* dfs(Node* node , unordered_map<Node*,Node*>&mp){
        Node* clone=new Node(node->val);
        mp[node]=clone;
        
        for(auto nbr : node->neighbors){
            if(mp.find(nbr)!=mp.end())
            clone->neighbors.push_back(mp[nbr]);
            
            else
            clone->neighbors.push_back(dfs(nbr,mp));
        }
        
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
        return NULL;
        
        if(node->neighbors.size()==0){
            Node* newHead=new Node(node->val);
            return newHead;
        }
        unordered_map<Node*,Node*>mp;
        
        return dfs(node,mp);
    }
};