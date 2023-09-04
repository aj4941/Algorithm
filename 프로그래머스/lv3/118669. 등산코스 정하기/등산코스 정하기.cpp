#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 50002;
vector<pii> g[N];
bool cache[N];

vector<int> solution(int n, vector<vector<int>> paths,
                     vector<int> gates, vector<int> summits) 
{
    vector<int> ans;
    
    for (auto to : paths)
    {
        int u = to[0], v = to[1], w = to[2];
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    
    for (auto to : summits)
        cache[to] = true;
    
    int l = -1, r = 1e9;
    int ans_p = 1e9, ans_i = 1e9;
    
    while (l + 1 < r) // (l, r]
    {
        vector<int> p(n + 1, -1);
        int mid = (l + r) / 2;
        // cout << mid << endl;
        queue<int> q;
        
        for (auto to : summits)
        {
            p[to] = to;
            q.push(to);
        }
        
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            for (auto to : g[v])
            {
                int nv = to.first, w = to.second;
                if (w > mid || cache[nv]) continue;
                if (p[nv] == -1 || p[v] < p[nv])
                {
                    p[nv] = p[v];
                    q.push(nv);
                }
            }
        }
        
        bool flag = false;
        
        for (auto to : gates)
        {
            // cout << to << ' ' << p[to] << endl;
            if (p[to] == -1) continue;
            flag = true;
            if (mid < ans_i)
            {
                ans_i = mid;
                ans_p = p[to];
                // cout << "ok" << endl;
            }
            else if (mid == ans_i)
            {
                if (p[to] < ans_p)
                {
                    ans_p = p[to];
                    // cout << "ok" << endl;
                }    
                
                
            }
        }
        
        if (flag) r = mid;
        else l = mid;
    }
    
    return { ans_p, ans_i };
}