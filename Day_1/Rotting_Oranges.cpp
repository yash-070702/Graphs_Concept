#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m , n ;
    
    bool isSafe(int x , int y ){
        return (x>=0 && y>=0 && x<m && y<n);
    }

    int orangesRotting(vector<vector<int>>& grid) {

    vector<vector<int>>directions{{1,0},{0,1},{0,-1},{-1,0}};
    m=grid.size();
    n=grid[0].size();

    int fresh=0;
    int count=0;
    queue<pair<int,int>>q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2)
            q.push({i,j});

            else if(grid[i][j]==1)
            fresh++;
        }
    }
    while(!q.empty()){ 
        int size=q.size();
        bool turnedRotten=false;

        for(int i=0;i<size;i++){
            auto top=q.front();
            q.pop();

            for(auto dir : directions){
            int new_x=top.first+dir[0];
            int new_y=top.second+dir[1];

            if(isSafe(new_x,new_y) && grid[new_x][new_y]==1){
            grid[new_x][new_y]=2;
            fresh--;
            turnedRotten=true;
            q.push({new_x,new_y});
            }
        }
    }
    
            if(turnedRotten)
            count++;
    }
    return fresh==0?count:-1;
    }
};