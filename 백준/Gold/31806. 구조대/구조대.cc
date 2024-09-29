#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
unordered_map<ll, ll> mp;
vector<pll> v1, v2;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll l, r, c; cin >> l >> r >> c;
        v1.push_back({ l, c }); v2.push_back({ r - 1, c });
    }

    sort(v1.rbegin(), v1.rend()); sort(v2.rbegin(), v2.rend());
    ll res = 0, ans = 0;

    for (int i = 0; i <= m; i++)
    {
        while (v1.size() && v1.back().first == i)
        {
            mp[v1.back().second]++;
            if (mp[v1.back().second] == 2) res++;
            v1.pop_back();
        }
    }

    ll l = 0, r = m;
    ans = res;

    while (true)
    {
        if (r + 1 > 1e6) break;

        while (v2.size() && v2.back().first == l)
        {
            mp[v2.back().second]--;
            if (mp[v2.back().second] == 1) res--;
            v2.pop_back();
        }

        l++; r++;

        while (v1.size() && v1.back().first == r)
        {
            mp[v1.back().second]++;
            if (mp[v1.back().second] == 2) res++;
            v1.pop_back();
        }

        ans = max(ans, res);
    }

    cout << ans;
}