#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> directions = {
    {-1, 0},  // Up
    {1, 0},   // Down
    {0, -1},  // Left
    {0, 1},   // Right
    {-1, -1}, // Up-Left
    {-1, 1},  // Up-Right
    {1, -1},  // Down-Left
    {1, 1}    // Down-Right
};
     
    bool isSafe(int x ,int y , int &n ){
        return (x>=0 && y>=0 && x<n && y<n);
    } 

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
        return -1;

        queue<pair<int,int>>q;
        q.push({0,0});

        int count=0;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();

                int x=top.first;
                int y=top.second;

                if(x==n-1 && y==n-1)
                return count+1;

                for(auto dir : directions){
                    int nx=x+dir.first;
                    int ny=y+dir.second;

                    if(isSafe(nx,ny,n) && grid[nx][ny]==0){
                        grid[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }

            }
            count++;
        }

       return -1;
    }
};