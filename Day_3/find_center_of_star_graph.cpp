#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       int n=edges.size()+1;
       vector<int>indegree(n+1,0);

       for(auto edge : edges){
        indegree[edge[0]]++;
        indegree[edge[1]]++;

        if(indegree[edge[0]]==n-1)
        return edge[0];

        if(indegree[edge[1]]==n-1)
        return edge[1];
       }
        return -1;
    }
};