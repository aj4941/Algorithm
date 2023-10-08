#include <bits/stdc++.h>
using namespace std;
vector<string> bvec[10];
map<string, int> mp;
int ans = 0;
int sz = 0;

bool calc(string a, string b)
{
    if (a.size() != b.size())
        return false;
    
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i] || a[i] == '*') continue;
        return false;
    }
    return true;
}

set<vector<string>> st;

void dfs(int idx)
{
    if (idx == sz)
    {
        vector<string> tmp;
        for (auto to : mp) tmp.push_back(to.first);
        sort(tmp.begin(), tmp.end());
        st.insert(tmp);
        return;
    }
    
    for (auto to : bvec[idx])
    {
        if (mp.count(to)) continue;
        mp[to] = 1;
        dfs(idx + 1);
        mp.erase(to);
    }
}

int solution(vector<string> u, vector<string> b) 
{
    sz = b.size();
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < u.size(); j++)
        {
            if (calc(b[i], u[j]))
                bvec[i].push_back(u[j]);
        }
    }
    dfs(0);
    
    return st.size();
}