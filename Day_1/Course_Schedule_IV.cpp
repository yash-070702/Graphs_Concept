#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    unordered_map<int, list<int>> adj;
    vector<int> indegree(numCourses, 0);
    vector<set<int>> isPre(numCourses);  

  
    for (auto& pre : prerequisites) {
        adj[pre[0]].push_back(pre[1]);
        indegree[pre[1]]++;
    }

   
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int course = q.front();
        q.pop();

        for (int neighbor : adj[course]) {
            isPre[neighbor].insert(course);
            for (int pre : isPre[course]) {
                isPre[neighbor].insert(pre);
            }

            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    vector<bool> result;
    for (auto& q : queries) {
        result.push_back(isPre[q[1]].count(q[0]) > 0);
    }

    return result;
}
};