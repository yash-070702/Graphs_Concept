#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<int, list<int>>adjList;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    vector<int> tInsertion;
    vector<int> tLow;
    void tarjanAlgorithm(int src, int parent,int timer) {
        timer++;
        visited[src] = true;
        tInsertion[src] = timer;
        tLow[src] = timer;
        
        for (auto nbr : adjList[src]) {
            if (parent == nbr) {
                continue;
            }
            else if (!visited[nbr]) {
                tarjanAlgorithm(nbr, src , timer);
                tLow[src] = min(tLow[src], tLow[nbr]);

                if (tInsertion[src] < tLow[nbr]) {
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
            else {
                tLow[src] = min(tLow[src], tLow[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       
        int src = 0;
        int parent = -1;

        tInsertion.resize(n);
        tLow.resize(n);

        
        
        int timer = 0;

        for (auto it1 : connections) {
            adjList[it1[0]].push_back(it1[1]);
            adjList[it1[1]].push_back(it1[0]);
        }

        tarjanAlgorithm(src, parent,timer);
        
        return ans;
    }
};