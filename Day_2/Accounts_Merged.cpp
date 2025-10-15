#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int>parent;
    vector<int>rank;

    void makeSet(){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findParent(int node)
    {
        if(parent[node]==node)
        return parent[node];

        return parent[node]=findParent(parent[node]);
    }

    void DSUSet(int u , int v){
        u=findParent(u);
        v=findParent(v);

        if(rank[u]>rank[v])
        parent[v]=u;

        else if(rank[v]>rank[u])
        parent[u]=v;

        else{
        parent[u]=v;
        rank[v]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
     n=accounts.size();
     rank.assign(n,0);
     parent.assign(n,-1);

     makeSet();

     unordered_map<string,int>mp;

     for(int i=0;i<n;i++){
      for(int j=1;j<accounts[i].size();j++){
        string email=accounts[i][j];

        if(mp.find(email)==mp.end()){
        mp[email]=i;
        }

        else
        DSUSet(mp[email],i);
      }
     }

     unordered_map<int,set<string>>merged;


     for(auto entry : mp){
        int parent=findParent(entry.second);
        merged[parent].insert(entry.first);
     }

     vector<vector<string>>str;

     for(auto entry:merged){
        vector<string>temp;
        temp.push_back(accounts[entry.first][0]);

        for(auto emails:entry.second){
            temp.push_back(emails);
        }

        str.push_back(temp);
     }
    return str;
    }
};
