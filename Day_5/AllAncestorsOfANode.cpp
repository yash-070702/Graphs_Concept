#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       unordered_map<int,list<int>>adj;
       vector<int>indegree(n,0);
       queue<int>q;

       for(auto edge : edges){
       adj[edge[0]].push_back(edge[1]);
       indegree[edge[1]]++;
       }
       
       for(int i=0;i<n;i++){
        if(indegree[i]==0)
        q.push(i);
       }
       vector<set<int>>result(n);

       while(!q.empty()){
       int top=q.front();
       q.pop();

       for(int nbr : adj[top]){
        result[nbr].insert(top);
        result[nbr].insert(result[top].begin(),result[top].end());
        indegree[nbr]--;
        if(indegree[nbr]==0)
        q.push(nbr);
       }
       }
       vector<vector<int>> answer(n);
        for(int i=0;i<n;i++){
            answer[i] = vector<int>(result[i].begin(), result[i].end());
        }

        return answer;
    }
};
