#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src, dest, weight;

    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
};

void makeSet(int n , vector<int>&parent , vector<int>&rank) {
    for(int i=0;i<n;i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node,vector<int>&parent){
    if(parent[node]==node){
        return node;
    }

    return parent[node]=findParent(parent[node],parent);;
}

void unionSet(int u, int v , vector<int>&parent, vector<int>&rank){
    u=findParent(u,parent);
    v=findParent(v,parent);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int minMST(int n , vector<Edge>&edges){
    sort(edges.begin(),edges.end(),comp);

    vector<int>parent(n);
    vector<int>rank(n);
    makeSet(n,parent,rank);

    int minCost=0;
    for(auto edge:edges){
        int u=edge.src;
        int v=edge.dest;
        int w=edge.weight;
        
        u=findParent(u,parent);
        v=findParent(v,parent);

        if(u!=v){
            minCost+=w;
            unionSet(u,v,parent,rank);
        }

    }
    return minCost;
}

int main(){
    int n,m;
    cout<<"Enter number of nodes and edges: ";
    cin>>n>>m;
    vector<Edge>edges;
    cout<<"Enter edges (u v w): \n";
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(Edge(u,v,w));
    }
    cout<<"Minimum cost of spanning tree is: ";
    cout<<minMST(n,edges)<<endl;
}