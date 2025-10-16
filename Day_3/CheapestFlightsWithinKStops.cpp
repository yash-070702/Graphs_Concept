#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights) adj[f[0]].push_back({f[1], f[2]});

        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> minHeap;
        minHeap.push({0, {src, 0}});

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while(!minHeap.empty()) {
            auto top = minHeap.top(); minHeap.pop();
            int cost = top.first, node = top.second.first, stops = top.second.second;

            if(node == dest) return cost;
            if(stops > k) continue;

            for(auto &nbr : adj[node]) {
                int next = nbr.first, price = nbr.second;
                if(cost + price < dist[next][stops+1]) {
                    dist[next][stops+1] = cost + price;
                    minHeap.push({dist[next][stops+1], {next, stops+1}});
                }
            }
        }

        return -1;
    }
};
