#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int bellManFord(vector<Edge>&edges,int v , int e , int src,int dest){
vector<int>dist(v,INT_MAX);
dist[src]=0;

for(int i=0;i<v-1;i++){
    for(int j=0;j<e;j++){
        int u=edges[j].src;
        int v=edges[j].dest;
        int w=edges[j].weight;

        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            dist[v]=dist[u]+w;
        }
    }
}
bool flag=false;

 for(int j=0;j<e;j++){
        int u=edges[j].src;
        int v=edges[j].dest;
        int w=edges[j].weight;

        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            flag=true;
            dist[v]=dist[u]+w;
        }
    }
    if(flag){
        cout<<"Negative Cycle is present"<<endl;
        return -1;
    }
        cout<<"No Negative Cycle is present"<<endl;
        return dist[dest];
    
}


int main(){
    int v=5;
    int e=8;
    vector<Edge>edges;

    edges.push_back({0,1,-1});
    edges.push_back({0,2,2});
    edges.push_back({1,3,3});
    edges.push_back({1,4,5});
    edges.push_back({3,2,4});
    edges.push_back({4,3,6});

    int src=0;
    int dest=3;

    int ans=bellManFord(edges,v,e,src,dest);
    if(ans!=-1){
        cout<<"Shortest distance from "<<src<<" to "<<dest<<" is "<<ans<<endl;
    }
    
}