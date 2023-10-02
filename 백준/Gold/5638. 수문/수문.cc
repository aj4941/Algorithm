#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int dx[8] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int n, m;
vector<pll> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll g, c; cin >> g >> c;
        v.push_back({ g, c });
    }
    cin >> m;
    for (int tc = 1; tc <= m; tc++)
    {
        ll w, t; cin >> w >> t;
        ll ans = 1e18;
        for (int bit = 0; bit < (1 << n); bit++)
        {
            ll res = 0, cw = 0;
            for (int i = 0; i < n; i++)
            {
                if (bit & (1 << i))
                {
                    res += v[i].second;
                    cw += v[i].first * t;
                }
            }

            if (cw >= w)
                ans = min(ans, res);
        }

        cout << "Case " << tc << ": ";
        if (ans == 1e18) cout << "IMPOSSIBLE";
        else cout << ans;
        cout << "\n";
    }
}