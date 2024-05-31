#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const int N = 1022;
ll n, m, A, D;
ll a[N], dp[N][N];

ll solve(int x, int cnt)
{
    if (x >= n) return 0;
    ll &ret = dp[x][cnt];
    if (ret != -1) return ret;
    ret = a[x] + solve(x + 1, cnt);
    if (cnt > 0) ret = max(ret, solve(x + D, cnt - 1) + A);
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> A >> D;

    for (int cnt = 0; cnt <= n; cnt++)
    {
        ll res = solve(0, cnt);
        if (res >= m)
        {
            cout << cnt;
            return 0;
        }
    }

    cout << -1;
}
