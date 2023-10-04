#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
unordered_map<string, vector<int>> mp;

vector<string> parse(string s)
{
    stringstream sr(s);
    vector<string> v;
    string w;
    while (getline(sr, w, ' '))
        v.push_back(w);
    
    return v;
}

string prv[5];

void dfs(int idx, vector<string> &t)
{
    if (idx == 4)
    {
        string tmp = "";
        for (int i = 0; i < 4; i++) tmp += prv[i];
        mp[tmp].push_back(stoi(t[4]));
        return;
    }
    
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) prv[idx] = t[idx];
        else prv[idx] = "-";
        dfs(idx + 1, t);
    }
}

vector<int> solution(vs info, vs query) 
{
    for (auto to : info)
    {
        vector<string> t = parse(to);
        dfs(0, t);
    }
    
    for (auto &to : mp)
        sort(to.second.begin(), to.second.end());
    
    vector<int> ans;
    
    for (auto to : query)
    {
        vector<string> t = parse(to);
        vector<string> v;
        for (auto to : t)
        {
            if (to == "and") continue;
            v.push_back(to);
        }
        
        string tmp = "";
        for (int i = 0; i < 4; i++) tmp += v[i];
        vector<int> res = mp[tmp];
        // sort(res.begin(), res.end());
        int num = stoi(v[4]);
        
        int idx = lower_bound(res.begin(), res.end(), num) - res.begin();
        ans.push_back(res.size() - idx);
    }
    
    return ans;
}