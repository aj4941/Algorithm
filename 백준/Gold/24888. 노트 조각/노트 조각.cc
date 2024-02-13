#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 200002;
int n, m;
vector<pll> g[N];
ll a[N], dist[N], cnt[N];
ll total = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = 1e17;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    priority_queue<pll> pq; pq.push({ 0, 1 }); dist[1] = 0;
    cnt[1] = (a[1] == 1 ? 1 : 0);

    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        ll w = -to.first, v = to.second;
        if (dist[v] != w) continue;
        for (auto to : g[v])
        {
            ll nv = to.first, c = to.second;
            if (dist[v] + c < dist[nv])
            {
                dist[nv] = dist[v] + c;
                pq.push({ -dist[nv], nv });
                cnt[nv] = cnt[v] + (a[nv] == 1 ? 1 : 0);
            }
            else if (dist[v] + c == dist[nv])
                cnt[nv] = max(cnt[nv], cnt[v] + (a[nv] == 1 ? 1 : 0));
        }
    }

    if (cnt[n] != total)
    {
        cout << -1;
        return 0;
    }

    vector<ll> ans;
    queue<ll> q; q.push(n);

    while (!q.empty())
    {
        ll v = q.front(); q.pop();
        ans.push_back(v);

        if (v == 1)
            break;

        for (auto to : g[v])
        {
            ll nv = to.first, w = to.second;
            if (dist[v] == dist[nv] + w)
            {
                if (cnt[v] == cnt[nv] + (a[v] == 1 ? 1 : 0))
                {
                    q.push(nv);
                    break;
                }
            }
        }
    }

    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for (auto to : ans) cout << to << ' ';
}