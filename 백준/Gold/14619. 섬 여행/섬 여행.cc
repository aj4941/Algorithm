#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, m, k;
const int N = 102;
const int K = 502;
int a[N];
int dp[N][K];
vector<int> g[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = a[i];
        for (int j = 1; j < K; j++)
            dp[i][j] = 1e9;
    }

    for (int c = 1; c < K; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int ni : g[i])
                dp[ni][c] = min(dp[ni][c], dp[i][c - 1]);
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, c; cin >> x >> c;
        int ans = dp[x][c];
        if (ans == 1e9) ans = -1;
        cout << ans << "\n";
    }
}