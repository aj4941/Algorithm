#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
int mul[2] = { -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, l, m; cin >> n >> l >> m;
    vector<pll> v;
    vector<ll> xpos, ypos;

    for (int i = 0; i < m; i++)
    {
        ll x, y; cin >> x >> y;
        v.push_back({ x, y });
        xpos.push_back(x); ypos.push_back(y);
    }

    ll ans = 0;

    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) for (int r = 1; r <= l; r++)
    {
        if (l - 2 * r <= 0 || (l - 2 * r) % 2) continue;
        int c = (l - 2 * r) / 2;
        if (r > n - 1 || c > n - 1) continue;
        for (int p1 = 0; p1 < 2; p1++) for (int p2 = 0; p2 < 2; p2++)
        {
            int x1 = xpos[i], y1 = ypos[j];
            int x2 = x1 + r * mul[p1], y2 = y1 + c * mul[p2];
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);

            ll res = 0;

            for (int k = 0; k < m; k++)
            {
                int x = v[k].first, y = v[k].second;
                if (x1 <= x && x <= x2 && y1 <= y && y <= y2)
                    res++;
            }

            ans = max(ans, res);
        }
    }

    cout << ans;
}