#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>bfsOfGraph(int V, unordered_map<int,list<int>>adj){
        vector<int>res;
        vector<int>visit(V,0);
        queue<int>q;

        q.push(0);
        visit[0]=1;

        while(!q.empty()){
            int front=q.front();
            q.pop();
            res.push_back(front);

            for(auto nbr : adj[front]){
                if(!visit[nbr]){
                    visit[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        return res;
    }
    };
