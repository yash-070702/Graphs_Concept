#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int m,n;

    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<m && y<n;
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<int>>directions{{1,0},{0,1},{0,-1},{-1,0}};
         m=board.size();
         n=board[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
            q.push({i,0});

            if(board[i][n-1]=='O')
            q.push({i,n-1});
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='O')
            q.push({0,j});

            if(board[m-1][j]=='O')
            q.push({m-1,j});
        }

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int x=top.first;
            int y=top.second;

            board[x][y]='#';


            for(auto dir : directions){
                int nx=dir[0]+x;
                int ny=dir[1]+y;

                if(isSafe(nx,ny) && board[nx][ny]=='O'){
                board[nx][ny]='#';
                q.push({nx,ny});

              }
           }
        }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]=='O')
                    board[i][j]='X';

                    else if(board[i][j]=='#')
                    board[i][j]='O';
                }
            }
    }
};
