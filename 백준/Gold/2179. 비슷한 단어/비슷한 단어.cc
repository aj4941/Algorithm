#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n; cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; i++) cin >> s[i];

    ll l = 0, r = 102;
    pll ans = pll(1e9, 1e9);

    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        map<string, vector<ll>> mp;
        for (ll i = 0; i < n; i++)
        {
            string t = s[i].substr(0, min(mid, (ll)s[i].size()));
            mp[t].push_back(i);
        }

        vector<pll> res;

        for (auto to : mp)
        {
            if (mp[to.first].size() >= 2)
                res.push_back({ mp[to.first][0], mp[to.first][1] });
        }

        sort(res.begin(), res.end());

        if (res.size())
        {
            l = mid;
            ans = res[0];
        }
        else
            r = mid;
    }

    cout << s[ans.first] << "\n" << s[ans.second];
}