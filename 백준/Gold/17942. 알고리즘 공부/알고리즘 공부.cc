#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100002;
vector<pll> g[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int k; cin >> k;
    for (int i = 0; i < k; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }

    ll l = 0, r = 1e15;

    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        vector<bool> cache(n + 1, false);
        vector<ll> sa = a;
        queue<ll> q;

        for (int i = 1; i <= n; i++)
        {
            if (sa[i] <= mid)
            {
                q.push(i); cnt++;
                cache[i] = true;
            }
        }

        while (!q.empty())
        {
            ll v = q.front(); q.pop();
            for (auto to : g[v])
            {
                ll nv = to.first, w = to.second;
                sa[nv] -= w;
                if (cache[nv]) continue;
                if (sa[nv] <= mid)
                {
                    q.push(nv);
                    cache[nv] = true;
                    cnt++;
                }
            }
        }

       // cout << mid << ' ' << cnt << endl;

        if (cnt >= m) r = mid;
        else l = mid;
    }

    cout << r;
}