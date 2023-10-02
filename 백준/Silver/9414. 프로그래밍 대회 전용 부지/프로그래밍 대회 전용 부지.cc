#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

ll mpow(ll a, ll x)
{
    if (x == 0) return 1;
    ll res = mpow(a, x / 2);
    res = res * res;
    if (x % 2) res = res * a;
    return res;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        vector<ll> a;
        while (true)
        {
            ll x; cin >> x;
            if (x == 0) break;
            a.push_back(x);
        }
        sort(a.rbegin(), a.rend());
        ll ans = 0;
        for (int i = 1; i <= a.size(); i++)
        {
            ans += 2 * mpow(a[i - 1], i);
            if (ans > 5 * 1e6) break;
        }

        if (ans > 5 * 1e6) cout << "Too expensive" << "\n";
        else cout << ans << "\n";
    }
}