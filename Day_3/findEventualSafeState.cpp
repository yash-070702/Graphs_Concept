#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int>isSafe;
    vector<int>visited;

    bool dfs(int node , vector<vector<int>>&graph){

    visited[node]=1;

    for(int nbr : graph[node]){
        if(visited[nbr]==0){
            if(!dfs(nbr,graph)){
            isSafe[node]=0 ;  
            return false;
            }
        }

        else{
            if (isSafe[nbr] == 0 || visited[nbr] == 1) {
                    isSafe[node] = 0;
                    return false;
                }
        }
    }
    visited[node]=2;
    isSafe[node]=1;
    return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      n=graph.size();
      isSafe.assign(n,-1);
      visited.assign(n,0);
      vector<int>result;

    

    for(int i=0;i<n;i++){
      if(isSafe[i]==-1){
       dfs(i,graph);
    } 
    }

     for(int i=0;i<n;i++){
        if(isSafe[i]==1)
        result.push_back(i);
     }
    return result;
    }
};

