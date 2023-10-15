#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<string>> vs;
unordered_map<string, int> pmp;
map<string, vector<string>> g;
vector<string> ans, res;
int cnt;
bool flag = false;

void dfs(string s, int cur)
{
    if (flag) 
        return;
    
    if (cur == cnt)
    {
        res = ans;
        flag = true;
        return;
    }
    
    for (string ns : g[s])
    {
        string tmp = s + ns;
        if (pmp[tmp] == 0) continue;
        ans.push_back(ns);
        pmp[tmp]--;
        dfs(ns, cur + 1);
        pmp[tmp]++;
        ans.pop_back();
    }
}

vector<string> solution(vs tickets) 
{
    cnt = tickets.size();
    
    for (auto to : tickets)
    {
        g[to[0]].push_back(to[1]);
        pmp[to[0] + to[1]]++;
    }
    
    for (auto to : g)
        sort(g[to.first].begin(), g[to.first].end());
    
    ans.push_back("ICN");
    dfs("ICN", 0);
    
    return res;
}