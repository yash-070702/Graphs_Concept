#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end());
        unordered_map<string, int> recipeset;
        unordered_map<string, int> indegree;
        unordered_map<string, list<string>> adj;

        int n = recipes.size();
        vector<string> result;

     
        for (int i = 0; i < n; i++) {
            recipeset[recipes[i]] = i;
        }

        
        for (int i = 0; i < n; i++) {
            for (string &ing : ingredients[i]) {
                if (recipeset.find(ing) != recipeset.end()) {
                    adj[ing].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;

       
        for (int i = 0; i < n; i++) {
            if (indegree.find(recipes[i]) == indegree.end())
                q.push(recipes[i]);
        }

        while (!q.empty()) {
            string currDish = q.front();
            q.pop();

            int index = recipeset[currDish];
            bool allAvailable = true;

           
            for (string &ing : ingredients[index]) {
                if (available.find(ing) == available.end()) {
                    allAvailable = false;
                    break;
                }
            }

            if (allAvailable) {
                result.push_back(currDish);
                available.insert(currDish);

              
                for (string &dep : adj[currDish]) {
                    indegree[dep]--;
                    if (indegree[dep] == 0)
                        q.push(dep);
                }
            }
        }

        return result;
    }
};
