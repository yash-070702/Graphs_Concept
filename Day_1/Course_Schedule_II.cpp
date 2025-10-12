#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int,list<int>>graph;
        queue<int>q;
        vector<int>indegree(numCourses,0);
        vector<int>ans;

        for(auto i:prerequisites){
        graph[i[1]].push_back(i[0]);
        indegree[i[0]]++;
        
    }

    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0)
        q.push(i);
    }

    int count=0;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        count++;

        for(auto i : graph[front]){
        indegree[i]--;
        if(indegree[i]==0)
        q.push(i);
    }
    }

 if(count==numCourses)
 return ans;

 return {};
    }
};