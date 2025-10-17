#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    
    void dfs(int i , vector<bool>&visited, vector<vector<int>>&stones){
        visited[i]=true;

        for(int a=0;a<n;a++){
            if(!visited[a]){
                if(stones[i][0]==stones[a][0] || stones[i][1]==stones[a][1])
                dfs(a,visited,stones);
            }
        }
    }

    
    int removeStones(vector<vector<int>>& stones) {

    n=stones.size();
    vector<bool>visited(n,false);

    int components=0;

    for(int i=0;i<n;i++){
        if(!visited[i])
        {
            components++;
            dfs(i,visited,stones);
        
           }
    }
return n- components;
    }
};