#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    ll mx = 0, ans = 0;

    for (ll val = 1e6; val >= 0; val--)
    {
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].first < val) continue;
            if (val - a[i].second < 0) continue;
            res += val - a[i].second;
        }

        if (mx <= res)
        {
            mx = res;
            ans = val;
        }
    }

    cout << ans;
}