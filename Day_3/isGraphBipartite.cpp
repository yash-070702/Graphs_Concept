#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int>color(n,-1);

       vector<bool>visited(n,false);
       color[0]=0;

       queue<int>q;
        

       for(int i=0;i<n;i++){
       if(visited[i]==true)
       continue;

       color[i]=1;
       q.push(i);

       while(!q.empty()){
        int top=q.front();
        q.pop();

        for(int nbr:graph[top]){
            if(visited[nbr]){
                if(color[top]==color[nbr])
                return false;
            }
            
            else{
                visited[nbr]=true;
                q.push(nbr);
                color[nbr]=(!color[top]);
            }
         }
       }
       }
       return true;
    }
};
