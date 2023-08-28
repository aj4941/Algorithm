#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100002;
const ll inf = 1000000009;
ll dp[N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= inf;
            }
        }
    }

    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        ll ans = 0;
        for (ll j = 0; j <= 3; j++)
        {
            ll rm = n - j;
            if (rm % 2) continue;
            ans += dp[rm / 2]; ans %= inf;
        }

        cout << ans << "\n";
    }
}
