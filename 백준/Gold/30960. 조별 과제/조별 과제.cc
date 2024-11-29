#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500002;
ll dp[N][4];
ll n;
vector<ll> a;

ll solve(int i, int j)
{
    if (i > n) return 1e15;
    if (i == n) return 0;
    ll &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = 1e15;
    if (i + 1 < n)
        ret = min(ret, solve(i + 2, j) + a[i + 1] - a[i]);
    if (j == 0)
    {
        if (i + 2 < n)
            ret = min(ret, solve(i + 3, 1) + a[i + 2] - a[i]);
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << solve(0, 0);
}