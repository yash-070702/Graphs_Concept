#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void makeSet(vector<int>&parent,vector<int>&rank,int n){

        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findParent(vector<int>&parent,int node){
        if(parent[node]==node)
        return node;

        return parent[node]=findParent(parent,parent[node]);
    }

    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }

    void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){
        u=findParent(parent,u);
        v=findParent(parent,v);

        if(rank[u]<rank[v])
         parent[u]=v;
        

        else if(rank[v]<rank[u])
         parent[v]=u;

        else
        {
            parent[v]=u;
            rank[u]++;
        } 

    }

    int minCostConnectPoints(vector<vector<int>>& points) {

           vector<vector<int>>edges;
           int n=points.size();
           vector<int>parent(n,0);
           vector<int>rank(n,0);

          for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i,j,dist});
            }
          }

            sort(edges.begin(),edges.end(),cmp);

            int minWeight=0;
            makeSet(parent,rank,n);

            for(int i=0;i<edges.size();i++){
                int u=findParent(parent,edges[i][0]);
                int v=findParent(parent,edges[i][1]);

                if(u!=v)
                {
                    int wt=edges[i][2];
                    minWeight+=wt;

                    unionSet(u,v,parent,rank);
                }
            }
            return minWeight;
        }
};