#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll inf = 1000000007;
ll n, c;
ll dp[1002][10002];
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=pasdfq&logNo=221368925855
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    dp[0][0] = 1;
    cin >> n >> c;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= c; j++)
        {
            dp[i - 1][j] += dp[i - 1][j - 1];
            dp[i - 1][j] %= inf;
        }
        for (ll j = 0; j <= c; j++)
        {
            ll r = dp[i - 1][j];
            ll l = j - (n - i + 1) >= 0 ? dp[i - 1][j - (n - i + 1)] : 0;
            dp[i][j] = (r - l + inf) % inf;
        }
    }

    cout << dp[n][c];
}