#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll inf = 1000000007;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 3002;
int n, m, t;
int dp[N][N], gas[N][N];

int solve(int x, int y)
{
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 1e9;
    if (x + 1 <= n) ret = min(ret, max(0, solve(x + 1, y) + 1 - gas[x][y]));
    if (y + 1 <= m) ret = min(ret, max(0, solve(x, y + 1) + 1 - gas[x][y]));

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> t;
    dp[n][m] = 0;
    for (int i = 0; i < t; i++)
    {
        int x, y, w; cin >> x >> y >> w;
        gas[x][y] = w;
    }

    cout << solve(1, 1);
}
