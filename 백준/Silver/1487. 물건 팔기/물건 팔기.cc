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
    vector<ll> v = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        v.push_back(a[i].first);
    }
    
    sort(v.begin(), v.end());

    ll mx = -1, ans = 0;

    for (auto value : v)
    {
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].first < value) continue;
            ll cost = value - a[i].second;
            if (cost > 0) res += cost;
        }

        if (mx < res)
        {
            mx = res;
            ans = value;
        }
    }

    cout << ans;
}