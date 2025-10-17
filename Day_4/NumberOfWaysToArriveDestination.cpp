#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        const int MOD=1e9+7;

        unordered_map<int,list<pair<int,int>>>adj;

        for(auto road : roads){
            int u=road[0];
            int v=road[1];
            int wt=road[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int u=top.second;
            long long wt=top.first;

            for(auto nbr:adj[u]){
                int v=nbr.first;
                int d=nbr.second;

                if(dist[v]>wt+d){
                    dist[v]=wt+d;
                    ways[v]=ways[u];
                    pq.push({dist[v],v});
                }

                else if (dist[v]==wt+d)
                 ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }

      return ways[n-1];
    }
};
