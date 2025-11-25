#include<bits/stdc++.h>
using namespace std;

void zeroOneBFS(int src, vector<vector<pair<int,int>>>& graph, int n) {
    deque<int> dq;
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    dq.push_front(src);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (auto &edge : graph[node]) {
            int adj = edge.first;
            int wt = edge.second;

            if (dist[node] + wt < dist[adj]) {
                dist[adj] = dist[node] + wt;
                if (wt == 0) dq.push_front(adj);
                else dq.push_back(adj);
            }
        }
    }
}
