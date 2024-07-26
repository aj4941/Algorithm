#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 1002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k, q; cin >> n >> k >> q;

    for (ll i = 0; i < q; i++)
    {
        ll x, y; cin >> x >> y;
        if (k == 1)
        {
            cout << abs(x - y) << "\n";
            continue;
        }
        ll cx = x, cy = y;
        ll depthX = 0, depthY = 0;
        while (cx > 0)
        {
            depthX++;
            cx = (cx + (k - 2)) / k;
        }
        while (cy > 0)
        {
            depthY++;
            cy = (cy + (k - 2)) / k;
        }

        if (depthX > depthY) swap(x, y);
        ll d = abs(depthY - depthX);
        ll ans = 0;

        while (d > 0)
        {
            y = (y + (k - 2)) / k;
            d--; ans++;
        }

        while (x != y)
        {
            x = (x + (k - 2)) / k;
            y = (y + (k - 2)) / k;
            ans += 2;
        }

        cout << ans << "\n";
    }
}