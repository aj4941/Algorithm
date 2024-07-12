#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const ll N = 1002;
ll dp[N][N], a[N];
ll n, m;

ll solve(int idx, int rm)
{
    ll &ret = dp[idx][rm];
    if (ret != -1) return ret;
    if (idx == n) return ret = 0;
    ret = 1e15;

    int minus = (rm == m) ? a[idx] : a[idx] + 1;

    // 새로운 줄
    ret = min(ret, solve(idx + 1, m - a[idx]) + rm * rm);
    if (rm - minus == 0) // 꽉 맞춘 경우
        ret = min(ret, solve(idx + 1, m));

    // 기존에 채우기
    if (rm - minus > 0)
        ret = min(ret, solve(idx + 1, rm - minus));

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);

    cout << solve(0, m);
}