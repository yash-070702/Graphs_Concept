#include<bits/stdc++.h>
using namespace std;

vector<int> Dikstra(vector<vector<int>>&graph, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : graph) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

       
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});


        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            int currDist = top.first;
            int u = top.second;
            minHeap.pop();

            for (auto& nbr : adj[u]) {
                int v = nbr.first;
                int w = nbr.second;
                if (dist[v] > currDist + w) {
                    dist[v] = currDist + w;
                    minHeap.push({dist[v], v});
                }
            }
        }

        return dist;
    }