#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, vector<int>& vis, vector<vector<int>>& isConnected) {
        vis[u] = 1;
        int n = isConnected.size();
        for (int v = 0; v < n; ++v) {
            if (!vis[v] && isConnected[u][v] == 1) dfs(v, vis, isConnected);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++count;
                dfs(i, vis, isConnected);
            }
        }
        return count;
    }
};
