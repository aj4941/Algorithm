#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
#define inf 1000000000
const ll N = 120;
ll dp[N][20][1 << 11], n;

ll solve(ll i, ll j, ll bit)
{
    ll& ret = dp[i][j][bit];
    if (ret != -1) return ret;
    if (i == n - 1) // 기저조건에 주의 (i == n으로 하면 틀림, 0부터 시작했으므로)
    {
        if (bit == ((1 << 10) - 1)) return ret = 1;
        else return ret = 0;
    }

    ret = 0;

    if (j - 1 >= 0)
    {
        ret += solve(i + 1, j - 1, bit | 1ll << (j - 1)) % inf;
        ret %= inf;
    }

    if (j + 1 <= 9)
    {
        ret += solve(i + 1, j + 1, bit | 1ll << (j + 1)) % inf;
        ret %= inf;
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i < 10; i++)
    {
        ans += solve(0, i, (1ll << i)) % inf;
        ans %= inf;
    }
    cout << ans;
}