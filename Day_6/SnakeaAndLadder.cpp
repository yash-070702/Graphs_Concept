#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// to find out the coordinates for a curr cell we use different concept as we dont know that currently we are moving left to right or right to left 
// for this purpose we wrote a another function called get coordinates

//at each cell we have changes to move 6 step that is from to 6 but if there is a snanke or a ladder then we can only move on the number that is mentioned on that cell of the board
    
    int n;

    pair<int,int>getCoord(int num){
        int rowTop=(num-1)/n;
        int rowBottom=n-1-rowTop;

        int col=(num-1)%n;

        if((!(n&1)&&!(rowBottom&1)) ||((n&1)&&(rowBottom&1)))  // condition for having left to right
        col=n-1-col;

        return make_pair(rowBottom,col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        int steps=0;

        queue<int>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[n-1][0]=true;

        q.push(1);

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                int top=q.front();
                q.pop();

                if(top==n*n)
                return steps;

                for(int j=1;j<=6;j++){
                    int val=top+j;

                    if(val>n*n)
                    break;

                    pair<int,int>coord=getCoord(val);

                    int r=coord.first;
                    int c=coord.second;

                    if(!visited[r][c]){
                        visited[r][c]=true;

                        if(board[r][c]==-1)
                        q.push(val);

                        else
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};