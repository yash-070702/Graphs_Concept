#include<bits/stdc++.h>
using namespace std;
stack<int>st;
unordered_map<int,bool>visited;
unordered_map<int,list<int>>adj;
unordered_map<int,list<int>>transpose;

void dfs1(int node){
    visited[node]=true;
    
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
         dfs1(nbr);
        }
    }
    st.push(node);
}

void revdfs(int node){
    visited[node]=true;
    
    for(auto nbr : transpose[node]){
        if(!visited[nbr]){
         revdfs(nbr);
        }
    }
}

int stronglyConnected(int n){

    for(int i=0;i<n;i++){
     if(!visited[i])
        dfs1(i);
    }
    
     
    for(int i=0;i<n;i++){
        visited[i]=false;

        for(auto nbr : adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    int count=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        
        if(!visited[top]){
            count++;
            revdfs(top);
        }
    }
    return count;       
}

int main(){
    int n,e;
    cout<<"Enter number of nodes and edges\n";
    cin>>n>>e;
    cout<<"Enter edges\n";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<stronglyConnected(n);
    return 0;
}