#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const int N = 1002;
vector<pii> g[N];
int dist[N], indegree[N], goal[N], bef[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    memset(goal, -1, sizeof goal);

    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
        if (v == 1) goal[u] = max(goal[u], w);
        indegree[v]++;
    }

    memset(dist, -1, sizeof dist);
    queue<int> q; q.push(1); dist[1] = 0;

    while (!q.empty())
    {
        int v = q.front(); q.pop();

        for (auto to : g[v])
        {
            int nv = to.first, w = to.second;
            indegree[nv]--;

            if (dist[nv] < dist[v] + w)
            {
                dist[nv] = dist[v] + w;
                bef[nv] = v;
            }

            if (nv != 1 && indegree[nv] == 0)
                q.push(nv);
        }
    }

    int ans = 0, pos = 1;

    for (int v = 2; v <= n; v++)
    {
        if (dist[v] == -1 || goal[v] == -1) continue;

        if (ans < dist[v] + goal[v])
        {
            ans = dist[v] + goal[v];
            pos = v;
        }
    }

    cout << ans << "\n";

    int v = pos;
    vector<int> road = { 1 };

    while (true)
    {
        road.push_back(v);
        if (v == 1) break;
        v = bef[v];
    }

    reverse(road.begin(), road.end());

    if (road.size() == 2)
    {
        cout << 1;
        return 0;
    }

    for (auto to : road)
        cout << to << ' ';
}