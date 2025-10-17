#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
    int  n;
    
    bool isSafe(int x , int y){
        return x>=0 && y >=0 && x<n && y<n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int time=0;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){

                auto top=pq.top();
                pq.pop();
                
                int t=top[0];
                int x=top[1];
                int y=top[2];
                
                if(visited[x][y])
                continue;

                visited[x][y]=true;

                time=max(time,t);
                if (x == n - 1 && y == n - 1)
                return time;

                for(auto dir : directions){
                    int nx=x+dir[0];
                    int ny=y+dir[1];

                    if(isSafe(nx,ny) && visited[nx][ny]==false){
                        pq.push({grid[nx][ny],nx,ny});
                    }
        
        }
        }
        return time;
    }

};                                                                                                                                                                                                                                              