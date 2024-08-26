#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n + 1), dp(10004, 0); dp[0] = 1;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int M; cin >> M;
        for (int i = 1; i <= n; i++)
        {
            for (int m = a[i]; m <= M; m++)
            {
                if (dp[m - a[i]] == 0) continue;
                dp[m] += dp[m - a[i]];
            }
        }

        cout << dp[M] << "\n";
    }
}