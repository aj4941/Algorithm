#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n + 10);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> dp(n, -1e15);
    for (int i = n - 1; i >= 0; i--)
    {
        // 안누르는 경우
        ll value = (i + 1 < n) ? dp[i + 1] : 0ll;
        dp[i] = max(dp[i], value + a[i]);

        // 누르는 경우
        value = (i + 3 < n) ? dp[i + 3] : 0ll;
        dp[i] = max(dp[i], value + (a[i] + a[i + 1] + a[i + 2]) * 2);

    }

    cout << dp[0];
}