#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll dp[1002][17][17];
vector<pll> v;

ll solve(int idx, int a, int b)
{
    ll &ret = dp[idx][a][b];
    if (ret != -1) return ret;
    if (idx == v.size()) return ret = 0;

    ret = solve(idx + 1, a, b);
    if (a < 15) ret = max(ret, solve(idx + 1, a + 1, b) + v[idx].first);
    if (b < 15) ret = max(ret, solve(idx + 1, a, b + 1) + v[idx].second);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b;
    while (cin >> a >> b)
    {
        v.push_back({ a, b });
    }

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, 0);
}