#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300;
int f[N][N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        if (i != j)
            f[i][j] = 1e9;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        f[u][v] = min(f[u][v], w);
        f[v][u] = min(f[v][u], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        {
            if (f[i][k] == 1e9 || f[k][j] == 1e9) continue;
            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
    }

    int ans = 1e9, ans_idx = -1;

    for (int i = n; i >= 1; i--)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += f[i][j];

        if (sum <= ans)
        {
            ans = sum;
            ans_idx = i;
        }
    }

    cout << ans_idx;
}