#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool cmp(pll& a, pll& b)
{
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n; cin >> n;
    vector<pll> a(n);
    multiset<pll> ms;
    ll mn_val = 1e15;

    for (ll i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        a[i] = { x, y }; ms.insert({ x, y });
    }

    sort(a.begin(), a.end(), cmp);

    ll ans = 0;
    cout << ms.begin()->first << "\n"; // 1개

    for (ll i = 0; i < n - 1; i++) // n - 1개
    {
        auto to = ms.find({ a[i].first, a[i].second });
        ms.erase(to); mn_val = min(mn_val, a[i].first - a[i].second);
        ans += a[i].second;
        ll r1 = 1e15, r2 = 1e15;
        r1 = mn_val + a[i + 1].second;
        r2 = ms.begin()->first;

        cout << ans + min(r1, r2) << "\n";
    }


}