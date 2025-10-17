#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
    int m , n;
    
    bool isSafe(int x , int y){
        return x>=0 && y >=0 && x<m && y<n;
    }

    void bfs(vector<vector<char>>&grid, int i , int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int x=top.first;
            int y=top.second;
            
            for(auto dir : directions){
                int nx=dir[0]+x;
                int ny=dir[1]+y;

                if(isSafe(nx,ny) && (grid[nx][ny]=='1')){
                    grid[nx][ny]='0';
                    q.push({nx,ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
