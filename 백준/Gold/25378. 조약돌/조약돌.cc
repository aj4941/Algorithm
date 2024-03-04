#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const ll N = 3000;
bool move1[N][N];
ll dp[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    for (ll i = 0; i < n; i++)
    {
        bool hasAns = true;
        ll prv = a[i];
        for (ll j = i + 1; j < n; j++)
        {
            if (prv == a[j]) move1[i][j] = hasAns;
            else
            {
                move1[i][j] = false;
                if (prv > a[j]) hasAns = false;

                prv = abs(prv - a[j]);
            }
        }
    }

    for (ll i = 1; i < n; i++) dp[i] = 1e15;
    dp[0] = 1;

    for (ll i = 1; i < n; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (ll j = i - 1; j >= 0; j--)
        {
            if (move1[j][i])
                dp[i] = min(dp[i], (i - j) + dp[j - 1]);
        }
    }

    cout << dp[n - 1];
}