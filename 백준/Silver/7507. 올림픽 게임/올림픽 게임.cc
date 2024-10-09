#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, ll> tll;

bool cmp (tll& a, tll &b)
{
    if (get<0>(a) != get<0>(b))
        return get<0>(a) < get<0>(b);

    if (get<2>(a) != get<2>(b))
        return get<2>(a) < get<2>(b);

    return get<1>(a) < get<1>(b);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        ll n; cin >> n;
        vector<tll> v;
        for (ll i = 0; i < n; i++)
        {
            ll d, a, b; cin >> d >> a >> b;
            v.push_back({ d, a, b });
        }

        sort(v.begin(), v.end(), cmp);
        ll ans = 1;
        ll d = get<0>(v[0]), a = get<1>(v[0]), b = get<2>(v[0]);

        for (ll i = 1; i < n; i++)
        {
            ll cd = get<0>(v[i]), ca = get<1>(v[i]), cb = get<2>(v[i]);
            if (d != cd || b <= ca)
            {
                ans++;
                d = cd, a = ca, b = cb;
            }
        }

        cout << "Scenario #" << tc << ":" << "\n";
        cout << ans << "\n\n";
    }
}