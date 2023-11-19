#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, -1, 1 };
const int N = 20002;
ll n, m, k;
ll a[N], dp[N];

ll solve(int i)
{
    ll &ret = dp[i];
    if (ret != -1) return ret;
    ret = 1e15;
    if (i == n) return ret = 0;
    ll mn = 1e15, mx = -1e15, cnt = 1;
    for (int ni = i; ni < n && cnt <= m; ni++)
    {
        mn = min(mn, a[ni]), mx = max(mx, a[ni]);
        ret = min(ret, solve(ni + 1) + (k + cnt++ * (mx - mn)));
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(0);
}