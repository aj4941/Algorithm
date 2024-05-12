#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 0, 0, 0 };
int dy[4] = { 0, -1, -1, 1 };
const int N = 52;
ll dp[N][N][N][N];
ll n, m, c;
ll cache[N][N];
const ll inf = 1000007;

ll solve(int x, int y, int c, int k)
{
    ll &ret = dp[x][y][c][k];
    if (ret != -1) return ret;
    ret = 0;
    if (x == 1 && y == 1)
    {
        if (k == 0) return ret = 1;
        else return ret = 0;
    }
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || ny < 1) continue;
        if (cache[nx][ny] == 0)
        {
            ret += solve(nx, ny, c, k);
            ret %= inf;
        }
        else
        {
            if (k == 0) continue;
            if (c == 0)
            {
                ret += solve(nx, ny, cache[nx][ny], k - 1);
                ret %= inf;
            }
            else if (cache[nx][ny] < c)
            {
                ret += solve(nx, ny, cache[nx][ny], k - 1);
                ret %= inf;
            }
        }
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++)
    {
        int x, y; cin >> x >> y;
        cache[x][y] = i;
    }

    for (int i = 0; i <= c; i++)
    {
        int cnt = i - ((cache[n][m] > 0) ? 1 : 0);
        if (cnt < 0) cout << 0 << ' ';
        else cout << solve(n, m, cache[n][m], cnt) << ' ';
    }
}