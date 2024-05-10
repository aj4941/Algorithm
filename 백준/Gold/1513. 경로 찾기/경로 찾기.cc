#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, -1, 1 };
ll n, m, c;
ll dp[52][52][52][52];
int cache[52][52];
const ll inf = 1000007;
int cnt = 0;

ll solve(int x, int y, int c, int prv)
{
    ll &ret = dp[x][y][c][prv];
    if (ret != -1) return ret;
    ret = 0;
    if (x == n && y == m)
    {
        if (c == cnt) return ret = 1;
        else return ret = 0;
    }
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx > n || ny > m) continue;
        int pos = cache[nx][ny];
        if (pos == 0)
        {
            ret += solve(nx, ny, c, prv);
            ret %= inf;
        }
        else if (c + 1 <= cnt && prv < pos)
        {
            ret += solve(nx, ny, c + 1, pos);
            ret %= inf;
        }
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++)
    {
        ll x, y; cin >> x >> y;
        cache[x][y] = i;
    }

    int count = cache[1][1] > 0 ? 1 : 0;
    int prv = cache[1][1];
    for (int i = 0; i <= c; i++)
    {
        memset(dp, -1, sizeof dp);
        cout << solve(1, 1, count, prv) << " ";
        cnt++;
    }
}