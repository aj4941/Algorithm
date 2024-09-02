#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 100002;
vector<pii> g[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, s, e; cin >> n >> m >> s >> e;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    int l = 0, r = 1e6 + 1;

    while (l + 1 < r) // [l, r)
    {
        int mid = (l + r) / 2;
        queue<int> q; q.push(s);
        vector<bool> cache(n + 1, false); cache[s] = true;
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            for (auto to : g[v])
            {
                int nv = to.first, w = to.second;
                if (cache[nv]) continue;
                if (mid <= w)
                {
                    cache[nv] = true;
                    q.push(nv);
                }
            }
        }
        if (cache[e]) l = mid;
        else r = mid;
    }

    cout << l;
}