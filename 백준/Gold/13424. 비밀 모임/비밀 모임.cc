#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int dist[102][102];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;

        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        {
            if (i != j)
                dist[i][j] = 1e9;
        }

        for (int i = 0; i < m; i++)
        {
            int u, v, w; cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        for (int k = 1; k <= n; k++)
        {
            for (int a = 1; a <= n; a++) for (int b = 1; b <= n; b++)
            {
                if (dist[a][k] == 1e9 || dist[k][b] == 1e9) continue;
                dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
            }
        }

        int k; cin >> k;
        vector<int> v;

        for (int i = 0; i < k; i++)
        {
            int x; cin >> x;
            v.push_back(x);
        }

        int ans = 1e9;
        int ans_pos = -1;

        for (int pos = 1; pos <= n; pos++)
        {
            int res = 0;
            for (int i = 0; i < v.size(); i++)
                res += dist[v[i]][pos];


            if (res < ans)
            {
                ans = res;
                ans_pos = pos;
            }
        }

        cout << ans_pos << "\n";
    }
}
