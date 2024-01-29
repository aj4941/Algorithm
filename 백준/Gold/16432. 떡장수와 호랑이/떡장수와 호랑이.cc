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
const ll N = 2002;
ll dp[N][15];
vector<ll> a[N];
ll n, t;

ll solve(ll x, ll y)
{
    ll& ret = dp[x][y];
    if (ret != -1) return ret;
    if (x == t - 1) return ret = 1;
    ret = 0;
    for (ll ny = 0; ny < a[x + 1].size(); ny++)
    {
        if (a[x][y] != a[x + 1][ny])
            ret = max(ret, solve(x + 1, ny));
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        cin >> n;
        for (ll j = 0; j < n; j++)
        {
            ll x; cin >> x;
            a[i].push_back(x);
        }
    }

    ll ans = 0;
    for (ll ny = 0; ny < a[0].size(); ny++)
        ans = max(ans, solve(0, ny));

    if (ans == 0)
        cout << -1;
    else
    {
        ll x = -1, y = -1;
        for (ll i = 0; i < a[0].size(); i++)
        {
            if (dp[0][i] == 1)
            {
                x = 0, y = i;
                break;
            }
        }
        vector<ll> ans = { a[x][y] };
        while (x < t - 1)
        {
            for (ll i = 0; i < a[x + 1].size(); i++)
            {
                if (dp[x + 1][i] && a[x][y] != a[x + 1][i])
                {
                    ans.push_back(a[x + 1][i]);
                    x = x + 1, y = i;
                    break;
                }
            }
        }

        for (auto to : ans)
            cout << to << "\n";
    }
}