#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m ,n ;

    bool isSafe(int x , int y){
        return x>=0 && y>=0 && x<m && y<n;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         m=image.size();
         n=image[0].size();

        int initialColor=image[sr][sc];

        if (initialColor == color) 
        return image;

        vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>>q;

        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            for(auto dir : directions){
                int nx=top.first+dir[0];
                int ny=top.second+dir[1];

                if(isSafe(nx,ny) && image[nx][ny]==initialColor){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};