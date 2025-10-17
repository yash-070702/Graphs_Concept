#include<bits/stdc++.h>
using namespace std;

int prismAlgo(int V, unordered_map<int,list<pair<int,int>>>&adj){
     vector<int>dist(V,INT_MAX);
     vector<int>parent(V,-1);
     vector<bool> inMST(V, false);


     dist[0]=0;
    
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
      minHeap.push({0, 0});

      while(!minHeap.empty()){
        auto top=minHeap.top();
        int u=top.second;
        minHeap.pop();

        if(inMST[u]) continue;
        inMST[u]=true;
        
        for(auto nbr : adj[u]){
            int v=nbr.first;
            int w=nbr.second;
            if(!inMST[v] && dist[v]>w){
                dist[v]=w;
                minHeap.push({dist[v],v});
                parent[v]=u;
            }
        }
      }
    
        int cost = 0;
    for (int i = 0; i < V; i++) {
        if (dist[i] != INT_MAX) cost += dist[i];
    }

    return cost;
}