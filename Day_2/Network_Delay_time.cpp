#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        unordered_map<int,list<pair<int,int>>>adj;

        for(auto time : times){
            adj[time[0]].push_back(make_pair(time[1],time[2]));
        }

        set<pair<int,int>>st;
        st.insert(make_pair(0,k));
        vector<int>dist(n+1,INT_MAX);
        int maxTime=0;

        dist[k]=0;

        while(!st.empty()){
            auto top=*st.begin();
            st.erase(st.begin());
            
            int currTime=top.first;
            int currNode=top.second;

            for(auto nbr : adj[currNode]){
                if(dist[nbr.first]>currTime+nbr.second){
                    
                 if (dist[nbr.first] != INT_MAX)
                st.erase({dist[nbr.first], nbr.first});

                dist[nbr.first]=currTime+nbr.second;
                
                st.insert({dist[nbr.first],nbr.first});
            }
            }
        }
        for(int i=1;i<=n;i++){
                if(dist[i]==INT_MAX)
                return -1;

                maxTime=max(maxTime,dist[i]);
            }
        return maxTime;
    }


};
