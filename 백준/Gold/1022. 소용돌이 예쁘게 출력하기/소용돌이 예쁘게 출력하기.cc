#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
map<pll, ll> mp;
ll dx[4] = { 0, -1, 0, 1 };
ll dy[4] = { 1, 0, -1, 0 };

ll calc(ll x)
{
    ll len = 0;
    while (x > 0)
    {
        x /= 10;
        len++;
    }
    return len;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    ll x = 0, y = 0, c = 1, d = 0, value = 1;
    if (r1 <= x && x <= r2 && c1 <= y && y <= c2)
        mp[{ x, y }] = value;

    while (true)
    {
        for (ll i = 0; i < c; i++)
        {
            x += dx[d], y += dy[d]; value++;
            if (r1 <= x && x <= r2 && c1 <= y && y <= c2)
                mp[{ x, y }] = value;
        }

        d = (d + 1) % 4;
        if (d == 0 || d == 2) c++;

        if (mp.size() == (r2 - r1 + 1) * (c2 - c1 + 1)) break;
    }

    ll mx = 0;
    for (auto to : mp)
        mx = max(mx, calc(to.second));
    
    for (ll i = r1; i <= r2; i++)
    {
        for (ll j = c1; j <= c2; j++)
        {
            ll len = calc(mp[{ i, j }]);
            for (ll k = 0; k < mx - len; k++)
                cout << ' ';
            cout << mp[{ i, j }] << ' ';
        }
        cout << "\n";

    }
}