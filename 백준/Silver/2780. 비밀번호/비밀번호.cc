#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll inf = 1234567;
const ll N = 1002;
int b[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, { 0, -1, -1 } };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n;
ll dp[1002][20];
vector<int> g[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++)
    {
        int x = b[i][j];
        if (x == -1) continue;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= 4 || nj >= 3) continue;
            int nx = b[ni][nj];
            if (nx == -1) continue;
            g[nx].push_back(x);
        }
    }

    for (int i = 0; i <= 9; i++) dp[1][i] = 1;
    for (int c = 2; c <= 1000; c++)
    {
        for (int i = 0; i <= 9; i++)
        {
            // dp[c][i] += dp[c - 1][i];
            for (auto to : g[i])
            {
                dp[c][i] += dp[c - 1][to];
                dp[c][i] %= inf;
            }
        }
    }

    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n; cin >> n;
        ll ans = 0;
        for (int j = 0; j <= 9; j++)
        {
            ans += dp[n][j];
            ans %= inf;
        }
        cout << ans << "\n";
    }
}