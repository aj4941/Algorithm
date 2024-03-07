#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll dp[30][30][3];
ll n;

ll solve(ll rm, ll cnt, ll c)
{
    ll &ret = dp[rm][cnt][c];
    if (ret != -1) return ret;
    if (rm == 0) return ret = 1;
    ret = 0;
    for (ll k = 1; k <= cnt; k++)
    {
        if (c == 0) ret += solve(rm - 1, rm - (cnt - k + 1), 1);
        else ret += solve(rm - 1, rm - k, 0);
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof dp);
        cin >> n;
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        cout << solve(n, n, 0) + solve(n, n, 1) << "\n";
    }
}