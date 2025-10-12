#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> graph) {
        unordered_map<int,list<int>>adj;
        vector<int>indegree(n,0);
        queue<int>q;
        int count=0;
        vector<int>res;
        
        for(auto preq : graph){
            adj[preq[0]].push_back(preq[1]);
            indegree[preq[1]]++;
        }
        
       for(int i=0;i<n;i++){
           if(indegree[i]==0)
           q.push(i);
       }
       
       while(!q.empty()){
           int top=q.front();
           res.push_back(top);
           q.pop();
           count++;
           
           for(int nbr : adj[top]){
               indegree[nbr]--;
               if(indegree[nbr]==0)
               q.push(nbr);
           }
       }
      if(res.size()==n)
      return res;
      
      return {}; // means thjere is a cycle in the graph and topological sort is not possible
    }
};