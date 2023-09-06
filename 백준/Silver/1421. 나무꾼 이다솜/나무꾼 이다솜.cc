#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, c, w; cin >> n >> c >> w;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;

    for (ll L = 1; L <= 1e4; L++)
    {
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            ll value = (a[i] / L) * L * w;
            ll cost = ((a[i] - 1) / L) * c;
            res += max(0ll, value - cost);
        }

        ans = max(ans, res);
    }

    cout << ans;
}
