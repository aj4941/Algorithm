#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
int n, m;
ll dp[22][202];
vector<pll> a;

ll solve(int idx, int days)
{
    ll &ret = dp[idx][days];
    if (ret != -1) return ret;
    if (idx == m) return ret = 0;
    ret = solve(idx + 1, days); // 선택하지 않는 경우

    if (days + a[idx].first <= n)
        ret = max(ret, solve(idx + 1, days + a[idx].first) + a[idx].second);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll d, p; cin >> d >> p;
        a.push_back({ d, p });
    }

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0);
}