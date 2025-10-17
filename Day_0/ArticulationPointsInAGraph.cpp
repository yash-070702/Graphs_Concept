#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, list<int>> adjList;
    vector<int> tInsertion, tLow;
    unordered_map<int, bool> visited;
    vector<int> articulationPoints;
    int timer = 0;

    void tarjanArticulation(int src, int parent) {
        visited[src] = true;
        tInsertion[src] = tLow[src] = timer++;
        int childCount = 0; 

        for (auto nbr : adjList[src]) {
            if (nbr == parent) continue;

            if (!visited[nbr]) {
                tarjanArticulation(nbr, src);
                tLow[src] = min(tLow[src], tLow[nbr]);
                childCount++;

               
                if (parent != -1 && tLow[nbr] >= tInsertion[src]) {
                    articulationPoints.push_back(src);
                }
            } else {
             
                tLow[src] = min(tLow[src], tInsertion[nbr]);
            }
        }

      
        if (parent == -1 && childCount > 1) {
            articulationPoints.push_back(src);
        }
    }

    vector<int> findArticulationPoints(int n, vector<vector<int>>& connections) {
        tInsertion.resize(n);
        tLow.resize(n);
        timer = 0;

        for (auto &edge : connections) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }


        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                tarjanArticulation(i, -1);
            }
        }
        return articulationPoints;
    }
};