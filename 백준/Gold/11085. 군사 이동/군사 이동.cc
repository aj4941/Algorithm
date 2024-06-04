#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, pii>> edge;
vector<int> par;

int find(int v)
{
    if (par[v] == v) return v;
    else return par[v] = find(par[v]);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int p, w, c, v; cin >> p >> w >> c >> v;
    for (int i = 0; i < w; i++)
    {
       int u, v, x; cin >> u >> v >> x;
       edge.push_back({ x, { u, v }});
    }

    int l = 0, r = 1e9;
    while (l + 1 < r)
    {
        par.resize(p);
        for (int i = 0; i < p; i++) par[i] = i;
        int mid = (l + r) / 2;
        for (auto to : edge)
        {
            int w = to.first, u = to.second.first, v = to.second.second;
            if (w < mid) continue;
            u = find(u), v = find(v); par[u] = v;
        }

        if (find(c) == find(v)) l = mid;
        else r = mid;
        par.clear();
    }

    cout << l;
}