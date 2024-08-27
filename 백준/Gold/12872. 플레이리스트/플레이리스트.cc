#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 102;
const ll inf = 1000000007;
ll n, m, p;
ll dp[N][N];

ll solve(int i, int j)
{
    ll &ret = dp[i][j];
    if (ret != -1) return ret;
    if (i == p)
    {
        if (j == n) return ret = 1;
        else return ret = 0;
    }
    if (i < m)
        ret = solve(i + 1, j + 1) * (n - j) % inf;
    else
    {
        ret = 0;
        if (j + 1 <= n) ret = solve(i + 1, j + 1) * (n - j) % inf;
        ret += solve(i + 1, j) * (j - m) % inf;
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> p;
    cout << solve(0, 0);
}