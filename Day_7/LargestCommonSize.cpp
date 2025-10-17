#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    int n;

    void makeSet() {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v) return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
            size[u] += size[v];
        } else {
            parent[v] = u;
            rank[u]++;
            size[u] += size[v];
        }
    }

    int hcf(int a, int b) {
        if (b == 0)
            return a;
        return hcf(b, a % b);
    }

    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        n = maxNum + 1;

        rank.assign(n, 0);
        parent.resize(n);
        size.assign(n, 1);
        makeSet();

        unordered_map<int, int> factorNode;

        for (int num : nums) {
            for (int f = 2; f * f <= num; f++) {
                if (num % f == 0) {
                   
                    if (factorNode.count(f))
                        unionSet(num, factorNode[f]);
                    else
                        factorNode[f] = num;

                   
                    int other = num / f;
                    if (factorNode.count(other))
                        unionSet(num, factorNode[other]);
                    else
                        factorNode[other] = num;
                }
            }

            if (factorNode.count(num))
                unionSet(num, factorNode[num]);
            else
                factorNode[num] = num;
        }

        unordered_map<int, int> compCount;
        int maxSize = 0;

        for (int num : nums) {
            int p = findParent(num);
            compCount[p]++;
            maxSize = max(maxSize, compCount[p]);
        }

        return maxSize;
    }
};