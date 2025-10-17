#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    int n;

    void makeSet(){
        for(int i=1;i<=n;i++){
          parent[i]=i;
          rank[i]=0;
        }
    }

    int findParent(int node){
        if(parent[node]==node)
        return node;

        return parent[node]=findParent(parent[node]);
    }

    void unionSet(int u , int v){
        u=findParent(u);
        v=findParent(v);

        if(rank[u]<rank[v])
        parent[u]=v;

        else if(rank[v]<rank[u])
        parent[v]=u;
        
        else{
            parent[u]=v;
            rank[v]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    n=edges.size();

    rank.assign(n+1,0);
    parent.assign(n+1,-1);
    makeSet();
    
    vector<int>result;

    for(int i=0;i<n;i++){
    int u=edges[i][0];
    int v=edges[i][1];

    u=findParent(u);
    v=findParent(v);

    if(u==v){
        result={edges[i][0],edges[i][1]};
    }
    else{
        unionSet(u,v);
    }
    }
    return result;
    }
};