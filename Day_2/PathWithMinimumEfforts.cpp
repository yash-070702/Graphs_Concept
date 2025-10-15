#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     vector<vector<int>> directions = {{0, -1},{0, 1},{-1, 0},{1, 0}};

     bool isSafe(int x ,int y,int &m,int &n){
        return (x>=0 && x<m && y>=0 && y<n);
     }

    int minimumEffortPath(vector<vector<int>>& heights) {

        int m=heights.size();
        int n=heights[0].size();
        set<pair<int,pair<int,int>>>st;

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));

        result[0][0]=0;
        st.insert({0,{0,0}});
        
        while(!st.empty()){
            auto top=*(st.begin());
            st.erase(st.begin());

            int diff=top.first;
            int x=top.second.first;
            int y=top.second.second;

            for(auto dir:directions){
                int x_=x+dir[0];
                int y_=y+dir[1];

                if(isSafe(x_,y_,m,n)){
                    int absDiff=abs(heights[x][y]-heights[x_][y_]);
                    int maxDiff=max(absDiff,diff);

                    if(maxDiff<result[x_][y_]){
                        result[x_][y_]=maxDiff;
                        st.insert({maxDiff,{x_,y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};