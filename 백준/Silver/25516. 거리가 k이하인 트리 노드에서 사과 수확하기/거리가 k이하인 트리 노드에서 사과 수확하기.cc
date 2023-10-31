#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
vector<int> g[N];
int a[N];
int ans = 0;
int n, k;

void dfs(int v, int p, int d)
{
    ans += a[v];
    if (d == k) return;
    for (int nv : g[v])
    {
        if (nv == p) continue;
        dfs(nv, v, d + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dfs(0, 0, 0);

    cout << ans;
}