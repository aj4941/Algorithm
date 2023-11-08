#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, w; cin >> n >> w;
    vector<ll> a, b;
    for (int i = 0; i < n; i++)
    {
        ll t, s; cin >> t >> s;
        if (t == 3) a.push_back(s);
        else b.push_back(s);
    }
    sort(a.rbegin(), a.rend()); sort(b.rbegin(), b.rend());

    for (int i = 1; i < a.size(); i++) a[i] += a[i - 1];
    for (int i = 1; i < b.size(); i++) b[i] += b[i - 1];

    ll ans = 0;

    for (int i = 0; i <= a.size(); i++)
    {
        ll cur = (i == 0) ? 0 : a[i - 1];
        ll rm = w - (3 * i);
        if (rm < 0) break;
        ll l = 0, r = b.size() + 1; // b 사용 개수
        while (l + 1 < r) // [l, r)
        {
            ll mid = (l + r) / 2;
            if (rm - 5 * mid < 0) r = mid;
            else l = mid;
        }
        cur += (l == 0) ? 0 : b[l - 1];
        ans = max(ans, cur);
    }

    cout << ans;
}