#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n=rooms.size();
      vector<bool>visited(n,false);
      queue<int>q;

      q.push(0);
      visited[0]=true;

      while(!q.empty()){
        int top=q.front();
        q.pop();
        
        for(int key:rooms[top]){
            if(!visited[key])
            {
                visited[key]=true;
                q.push(key);
            }
        }
      }
      for(bool i : visited)
      {
        if(!i)
        return false;
      }
      return true;
    } 
};