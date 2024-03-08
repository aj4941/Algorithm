#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> a(2 * n + 5), sum(2 * n + 5);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];

        for (int i = 1; i <= 2 * n; i++)
        {
            sum[i] = a[i];
            sum[i] += sum[i - 1];
        }

        if (n == m)
        {
            ll ans = (sum[n] < k) ? 1 : 0;
            cout << ans << "\n";
            continue;
        }

        ll ans = 0;

        for (int i = 1; i <= n; i++)
        {
            int j = i + m - 1;
            if (j > 2 * n) break;
            ll value = sum[j] - sum[i - 1];

            if (value < k) ans++;

            // cout << "result : " << i << ' ' << j << ' ' << value << endl;
        }

        cout << ans << "\n";
    }
}