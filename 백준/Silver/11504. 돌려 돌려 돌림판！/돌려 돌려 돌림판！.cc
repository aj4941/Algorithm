#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        ll a = 0, b = 0;
        for (int i = 0; i < m; i++)
        {
            ll x; cin >> x;
            a = a * 10 + x;
        }

        for (int i = 0; i < m; i++)
        {
            ll x; cin >> x;
            b = b * 10 + x;
        }

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            ll res = 0;
            for (int j = 0; j < m; j++)
                res = res * 10 + v[(i + j) % n];

            if (a <= res && res <= b)
                ans++;
        }

        cout << ans << "\n";
    }
}