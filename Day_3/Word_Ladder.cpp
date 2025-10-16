#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>st(wordList.begin(),wordList.end());

       queue<pair<string,int>>q;
       q.push({beginWord,1});

       while(!q.empty()){
        auto top=q.front();
        q.pop();
        string word=top.first;
        int count=top.second;

        if(word==endWord)
        return count;

        for(int i=0;i<word.length();i++){
            string temp=word;
            for(char ch='a';ch<='z';ch++){
                temp[i]=ch;
                if(st.find(temp)!=st.end()){
                    st.erase(temp);
                    q.push({temp,count+1});
                }
            }
        }
       }
       return 0;
    }
};