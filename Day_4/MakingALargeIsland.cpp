#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    vector<vector<int>>directions{{1,0},{0,1},{0,-1},{-1,0}};
    int n;
    
    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<n && y<n;
    }

    int bfsMark(vector<vector<int>>&grid,int i , int j , int id){
        int area=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=id;

        while(!q.empty()){
            auto top=q.front();
            q.pop();
            area++;

            int x=top.first;
            int y=top.second;

            for(auto dir : directions){
                int nx=dir[0]+x;
                int ny=dir[1]+y;

                if(isSafe(nx,ny) && grid[nx][ny]==1)
                {
                    grid[nx][ny]=id;
                    q.push({nx,ny});
                }
            }
        }
        return area;
    }


    int largestIsland(vector<vector<int>>& grid) {
        int answer=0;
        n=grid.size();
        int id=2;
        unordered_map<int,int>areaId;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                areaId[id]=bfsMark(grid,i,j,id);
                id++;
                }

            }
        }

        int count=0;
 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==0){
                    count++;
                    int total=1;
                     unordered_set<int> seen;

                    for(auto dir : directions){
                        int nx=i+dir[0];
                        int ny=j+dir[1];

                        if(isSafe(nx,ny) && grid[nx][ny] > 1 && !seen.count(grid[nx][ny])){
                            seen.insert(grid[nx][ny]);
                            total += areaId[grid[nx][ny]];
                        }

                    }
                    answer=max(answer,total);
                }
            }
        }

        if(!count)
        return n*n;

        
        return answer;
    }
};