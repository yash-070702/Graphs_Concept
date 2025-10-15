#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     
     vector<int>rank;
    vector<int>parent;
    int n;

    void makeSet(){
        for(int i=0;i<n;i++){
          parent[i]=i;
          rank[i]=0;
        }
    }

    int findParent(int node){
        if(parent[node]==node)
        return node;

        return parent[node]=findParent(parent[node]);
    }

    void unionSet(int u , int v){
        u=findParent(u);
        v=findParent(v);

        if(rank[u]<rank[v])
        parent[u]=v;

        else if(rank[v]<rank[u])
        parent[v]=u;
        
        else{
            parent[u]=v;
            rank[v]++;
        }
    } 
      
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    n=s.size();
    rank.assign(n,0);
    parent.resize(n);
    makeSet();

    for(auto pair : pairs){
        unionSet(pair[0],pair[1]);
    }

    unordered_map<int,vector<int>>mp;

    for(int i=0;i<n;i++){
        mp[findParent(i)].push_back(i);
    }
     
    string result=s;

    for(auto it : mp){
        vector<char>str;
        for(int ind : it.second){
            str.push_back(s[ind]);
        }
        sort(it.second.begin(),it.second.end());
        sort(str.begin(),str.end());

        for(int i=0;i<it.second.size();i++){
            result[it.second[i]]=str[i];
        }
    }
    return result;
    }
};