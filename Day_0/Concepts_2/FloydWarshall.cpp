#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPairsShortestPath(int n, vector<vector<int>>& edges) {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++){
        dist[i][i] = 0;
    }
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = w;
    }
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]>dist[i][via]+dist[via][j]){
                    dist[i][j]=dist[i][via]+dist[via][j];
                }
            }
        }
    }

return dist;
    }   
};