#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 30002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int dp[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, n; cin >> c >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    dp[0] = 0;
    for (int i = 1; i <= 3000; i++) dp[i] = 1e9;

    for (int i = 0; i < n; i++)
    {
        for (int num = a[i].second; num <= 3000; num++)
            dp[num] = min(dp[num], dp[num - a[i].second] + a[i].first);
    }

    int ans = 1e9;
    for (int i = c; i <= 3000; i++) ans = min(ans, dp[i]);
    cout << ans;
}