#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
const ll inf = 1000000007;
ll dp[1002][1002];
ll n, m;

ll solve(int x, int y)
{
    ll &ret = dp[x][y];
    if (ret != -1) return ret;
    if (x == 1 && y == 1) return ret = 1;
    ret = 0;
    if (x - 1 >= 0) ret += solve(x - 1, y), ret %= inf;
    if (y - 1 >= 0) ret += solve(x, y - 1), ret %= inf;
    if (x - 1 >= 0 && y - 1 >= 0) ret += solve(x - 1, y - 1), ret %= inf;
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    cout << solve(n, m);
}
