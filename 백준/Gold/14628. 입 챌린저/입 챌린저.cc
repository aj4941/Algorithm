#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m, k;
ll dp[102];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 102; i++) dp[i] = 1e15;
    dp[0] = 0;
    cin >> n >> m >> k;
    vector<pll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    for (int i = 0; i < n; i++)
    {
        ll val = a[i].second;
        for (int j = 1; j <= 102; j++)
        {
            ll cost = a[i].first + (j - 1) * k;
            for (int x = 100; x >= 0; x--)
            {
                if (x - val < 0) break;
                dp[x] = min(dp[x], dp[x - val] + cost);
            }
        }
    }

    cout << dp[m];
}