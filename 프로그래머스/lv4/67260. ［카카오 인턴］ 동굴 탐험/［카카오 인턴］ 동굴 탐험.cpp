#include <bits/stdc++.h>
using namespace std;
const int N = 200020;
vector<int> g[N];
bool cache[N];
int reserve[N], fc[N];

void dfs(int v)
{
    cache[v] = true;
    for (int nv : g[v])
    {
        if (cache[nv]) continue;
        if (fc[nv] == -1) // 역방향 존재하지 않는 경우
        {
            if (reserve[nv] != -1) // 자신의 정점 예약여부 
                dfs(reserve[nv]);
            
            if (!cache[nv])
                dfs(nv);
        }
        else // 역방향 존재
        {
            if (cache[fc[nv]]) // 역방향 정점 방문 여부
                dfs(nv);
            else // 예약
                reserve[fc[nv]] = nv;
        }
    }
}

bool solution(int n, vector<vector<int>> path,
              vector<vector<int>> order) 
{
    for (auto to : path)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    memset(reserve, -1, sizeof reserve);
    memset(fc, -1, sizeof fc);
    
    for (auto to : order)
    {
        int u = to[0], v = to[1];
        fc[v] = u; // v -> u : 역방향 참조
    }
    
    if (fc[0] != -1)
        return false;
    
    dfs(0);
    
    bool ans = true;
    
    for (int i = 0; i < n; i++)
    {
        if (!cache[i])
            ans = false;
    }
    
    return ans;
}