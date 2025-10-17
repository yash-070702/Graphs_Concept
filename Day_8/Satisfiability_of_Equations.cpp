#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    void declareParent() {
        parent.resize(26);
        rank.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int node){
        if(parent[node]==node)
        return node;

        return parent[node]=findParent(parent[node]);
    }

    void unionSet(int x ,int y){
        x=findParent(x);
        y=findParent(y);

        if(rank[x]>rank[y])
        parent[y]=x;

        else if(rank[y]>rank[x])
        parent[x]=y;

        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
    declareParent();

    for(string &eq : equations){
        if(eq[1]=='=')
        unionSet(eq[0]-'a',eq[3]-'a');


    }
    for(string &eq : equations){
        if(eq[1]=='!')
        {
            if(findParent(eq[0]-'a')==findParent(eq[3]-'a'))
            return false;
        }
    }
    return true;
    }

};

