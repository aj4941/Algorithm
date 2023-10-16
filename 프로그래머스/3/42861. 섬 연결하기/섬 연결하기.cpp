#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
vector<pair<int, pii>> edge;
const int N = 102;
int p[N];

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int solution(int n, vi costs) 
{
    for (int i = 1; i <= n; i++) p[i] = i;
    for (auto to : costs)
    {
        int u = to[0], v = to[1], w = to[2];
        edge.push_back({ w, { u, v } });
    }
    
    sort(edge.begin(), edge.end());
    int ans = 0;
    
    for (auto to : edge)
    {
        int w = to.first;
        int u = to.second.first, v = to.second.second;
        if (find(u) == find(v)) continue;
        int nu = find(u), nv = find(v);
        p[nu] = nv;
        ans += w;
    }
    
    return ans;
}