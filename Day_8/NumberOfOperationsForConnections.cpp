#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    vector<int>rank;
    vector<int>parent;
    int n;

    void makeSet(){
        for(int i=0;i<n;i++){
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

    
    int makeConnected(int m, vector<vector<int>>& edges) {
        n=m;
        if(edges.size()<n-1)
        return -1;

        rank.assign(n,0);
        parent.assign(n,-1);
        makeSet();

        int result=0;

        for(int i=0;i<edges.size();i++){
         int u=edges[i][0];
         int v=edges[i][1];

         u=findParent(u);
         v=findParent(v);

    if(u!=v){
         unionSet(u,v);
    }
    }

        for(int i=0;i<n;i++){
        if(parent[i]==i)
        result++;
    }
    
    return result-1;    
    }
};