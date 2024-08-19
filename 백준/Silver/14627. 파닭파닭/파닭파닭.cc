#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 1002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll s, c; cin >> s >> c;
    vector<ll> v(s);
    for (int i = 0; i < s; i++) cin >> v[i];

    ll l = 1, r = 1e18;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;

        for (int i = 0; i < s; i++)
            cnt += v[i] / mid;

        if (cnt >= c) l = mid;
        else r = mid;
    }

    ll ans = 0, cnt = 0;

    for (int i = 0; i < s; i++)
    {
        ll inc = v[i] / l;
        ll mn = min(inc, c - cnt);
        ans += (v[i] - mn * l);
        cnt += mn;
    }

    cout << ans;
}