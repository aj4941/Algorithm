#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll idx = 0, val = 1;
    ll ans = 0;

    while (idx < n)
    {
        if (idx + 1 < n && (a[idx + 1] - a[idx]) <= k)
            val += a[idx + 1] - a[idx];
        else
        {
            ans += val + k;
            val = 1;
        }

        idx++;
    }

    cout << ans;
}