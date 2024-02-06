#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 2002;
vector<int> g[N];
int indegree[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int k, m, p; cin >> k >> m >> p;
        for (int i = 1; i <= m; i++)
        {
            g[i].clear();
            indegree[i] = 0;
        }

        vector<bool> cache(m + 1, false);

        for (int i = 0; i < p; i++)
        {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            indegree[v]++;
            if (indegree[v] >= 2)
                cache[v] = true;
        }

        queue<int> q;

        int ans = 0;
        vector<int> res(m + 1, -1), cur(m + 1, -1), cnt(m + 1, -1);

        for (int i = 1; i <= m; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                res[i] = 1;
            }
        }

        while (!q.empty())
        {
            int v = q.front(); q.pop();
            ans = max(ans, res[v]);
            for (int nv : g[v])
            {
                indegree[nv]--;
                if (cur[nv] < res[v])
                {
                    cur[nv] = res[v];
                    cnt[nv] = 1;
                }
                else if (cur[nv] == res[v])
                    cnt[nv]++;

                if (indegree[nv] == 0)
                {
                    if (cnt[nv] == 1)
                        res[nv] = cur[nv];
                    else
                        res[nv] = cur[nv] + 1;

                    q.push(nv);
                }
            }
        }

        cout << k << ' ' << ans << "\n";
    }
}