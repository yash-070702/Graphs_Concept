#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

     vector<vector<int>>result;
     vector<int>visit;


     void dfs(int currNode,int n,vector<vector<int>>&graph,vector<int>&arr){
     if(currNode==n-1)
     {
        arr.push_back(currNode);
        result.push_back(arr);
        arr.pop_back();
        return ;
     }

     arr.push_back(currNode);
     visit[currNode]=1;

     for(auto nbr : graph[currNode]){
        if(!visit[nbr])
        dfs(nbr,n,graph,arr);
     }

     arr.pop_back();
     visit[currNode]=0;
     }

     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
     int n = graph.size();
     visit.assign(n,0);

     vector<int>arr;

     dfs(0,n,graph,arr);

     return result;
     }



};
