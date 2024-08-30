#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 2000;
vector<int> g[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (true)
    {
        int n; cin >> n;
        if (n == 0) return 0;
        vector<int> cost(n + 1), indegree(n + 1);
        for (int i = 1; i <= n; i++) g[i].clear();

        for (int i = 1; i <= n; i++)
        {
            char c; cin >> c;
            int d; cin >> d;
            if (c == 'L') cost[i] = d;
            else if (c == 'T') cost[i] = -d;

            while (true)
            {
                int x; cin >> x;
                if (x == 0) break;
                g[i].push_back(x);
            }
        }

        vector<int> dist(n + 1, -1);
        queue<pii> q; q.push({ 0, 1 }); dist[1] = 0;

        while (!q.empty())
        {
            auto to = q.front(); q.pop();
            int d = to.first, v = to.second;
            if (dist[v] != d) continue;
            for (int nv : g[v])
            {
                int nd = -1;
                if (cost[nv] > 0)
                {
                    if (cost[nv] < dist[v]) nd = dist[v];
                    else nd = cost[nv];
                }
                else if (cost[nv] < 0)
                    nd = dist[v] + cost[nv];

                if (nd < 0) continue;
                if (dist[nv] < nd)
                {
                    dist[nv] = nd;
                    q.push({ dist[nv], nv });
                }
            }
        }

        if (dist[n] >= 0)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
}