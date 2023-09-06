#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll l = 0, r = 1e15;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += a[i] / mid;

        if (cnt >= k) l = mid;
        else r = mid;
    }

    cout << l;
}
