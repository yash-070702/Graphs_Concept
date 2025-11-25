#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }


        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int i = curr.first;
            int j = curr.second;
            for (auto dir : directions) {
                int dx = dir.first;
                int dy = dir.second;
                
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (dist[x][y] > dist[i][j] + 1) {
                        dist[x][y] = dist[i][j] + 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return dist;
    }

    
};