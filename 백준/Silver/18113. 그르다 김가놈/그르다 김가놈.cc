#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, k, m; cin >> n >> k >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= 2 * k) a[i] -= 2 * k;
        else if (a[i] >= k) a[i] -= k;
        else a[i] = 0;
    }

    ll l = 0, r = 1e18;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
            cnt += a[i] / mid;

        if (cnt >= m) l = mid;
        else r = mid;
    }

    if (l == 0) l = -1;

    cout << l;
}