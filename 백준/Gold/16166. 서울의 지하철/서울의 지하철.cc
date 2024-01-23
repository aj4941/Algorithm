#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAX = (1ll << 32 + 5);
map<ll, vector<pll>> g;
map<ll, ll> dist;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            ll x; cin >> x;
            g[x].push_back({ MAX + i, 0 });
            g[MAX + i].push_back({ x, 1 });
            dist[x] = dist[MAX + i] = 1e9;
        }
    }

    ll ed; cin >> ed;

    if (ed == 0)
    {
        cout << 0;
        return 0;
    }

    deque<ll> dq; dq.push_front(0);
    dist[0] = 0;

    // for (auto to : dist)
        // cout << to.second << endl;

    while (dq.size())
    {
        ll v = dq.front(); dq.pop_front();
        for (auto to : g[v])
        {
            ll nv = to.first, w = to.second;
            // cout << "nv : " << nv << endl;
            // cout << "dist : " << dist[nv] << endl;
            if (dist[v] + w < dist[nv])
            {
                dist[nv] = dist[v] + w;
                if (w == 0)
                    dq.push_front(nv);
                else
                    dq.push_back(nv);
            }
        }
    }

    if (dist[ed] == 1e9)
    {
        cout << -1;
        return 0;
    }

    cout << dist[ed] - 1;
}
