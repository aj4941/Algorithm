#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, -1, 1 };
const ll N = 200;
ll dp[N][N], n, m, k;
map<pll, set<pll>> mp;

ll solve(int x, int y)
{
    ll &ret = dp[x][y];
    if (ret != -1) return ret;
    if (x == n && y == m) return ret = 1;
    ret = 0;
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx > n || ny > m) continue;
        if (mp[{ x, y }].find({ nx, ny }) != mp[{ x, y}].end()) continue;
        ret += solve(nx, ny);
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        mp[{ x1, y1 }].insert({ x2, y2 });
        mp[{ x2, y2 }].insert({ x1, y1 });
    }

    cout << solve(0, 0);
}