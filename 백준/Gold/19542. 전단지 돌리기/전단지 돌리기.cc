#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
const int N = 100002;
int dist[N], mx_ver[N];
int n, s, d;
vector<int> g[N];
ll ans = 0;

int calc(int v, int p)
{
    mx_ver[v] = dist[v];
    for (int nv : g[v])
    {
        if (nv == p) continue;
        dist[nv] = dist[v] + 1;
        mx_ver[v] = max(mx_ver[v], dist[nv]);
        mx_ver[v] = max(mx_ver[v], calc(nv, v));
    }

    return mx_ver[v];
}

void dfs(int v, int p)
{
    for (int nv : g[v])
    {
        if (nv == p) continue;
        if (mx_ver[nv] - dist[v] > d)
        {
            dfs(nv, v);
            ans += 2;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s >> d;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    memset(dist, -1, sizeof dist);
    dist[s] = 0;
    calc(s, 0); dfs(s, 0);
    cout << ans;
}