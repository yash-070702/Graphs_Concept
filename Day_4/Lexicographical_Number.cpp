#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   


//   static bool cmp(string a , string b){
//     return b > a;
//    }

//    vector<int>lexicalOrder(int n){
//     vector<string>temp;
//     vector<int>ans;

//     for(int i=1;i<=n;i++){
//         temp.push_back(to_string(i));
//     }
//     sort(temp.begin(),temp.end(),cmp);

//     for(string ab : temp){
//         ans.push_back(stoi(ab));
//     }
//     return ans;
//    }

//<<<<<<<<============OR=============>>>>>>>>>>>

   void dfs(int curr , int n , vector<int>&arr){
    if(curr>n)
    return ;

    arr.push_back(curr);

    for(int i=0;i<=9;i++){
        dfs(curr*10+i,n,arr);
    }
   }

    vector<int>lexicalOrder(int n){
        vector<int>ans;
        for(int i=1;i<=9;i++){
            dfs(i,n,ans);
        }
        return ans;
    }
};