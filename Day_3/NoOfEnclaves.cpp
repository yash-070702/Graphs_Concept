#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;

    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
     
    int numEnclaves(vector<vector<int>>& grid){
    vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
    
    m=grid.size();
    n=grid[0].size();

    queue<pair<int,int>>q;

    for(int i=0;i<m;i++){
        if(grid[i][0]==1)
        q.push({i,0});

        if(grid[i][n-1]==1)
        q.push({i,n-1});
    }

    for(int i=0;i<n;i++){
        if(grid[0][i]==1)
        q.push({0,i});

        if(grid[m-1][i]==1)
        q.push({m-1,i});
    }
    
    while(!q.empty()){
        auto top=q.front();
        q.pop();

        int x=top.first;
        int y=top.second;

        grid[x][y]=0;

         
        for(auto dir : directions){
            int nx=dir[0]+x;
            int ny=dir[1]+y;

            if(isSafe(nx,ny) && grid[nx][ny]==1){
                grid[nx][ny]=0;
                q.push({nx,ny});
            }
        }
    }
     int count=0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)
            count++;
        }
     }
    return count;
    }
};