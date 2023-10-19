#include <bits/stdc++.h>
using namespace std;
unordered_map<string, vector<pair<int, int>>> mp;
unordered_map<string, int> sum;

vector<int> solution(vector<string> g, vector<int> p) 
{
    int n = g.size();
    for (int i = 0; i < n; i++)
    {
        mp[g[i]].push_back({ p[i], -i });
        sum[g[i]] += p[i];
    }
    
    vector<pair<int, string>> tmp;
    for (auto to : mp)
    {
        sort(mp[to.first].rbegin(), mp[to.first].rend());
        tmp.push_back({ sum[to.first], to.first });
    }
    
    sort(tmp.rbegin(), tmp.rend());
    
    vector<int> ans;
    
    for (auto to : tmp)
    {
        string s = to.second;
        for (int i = 0; i < min(2, (int)mp[s].size()); i++)
            ans.push_back(-mp[s][i].second);
    }
    
    return ans;
}