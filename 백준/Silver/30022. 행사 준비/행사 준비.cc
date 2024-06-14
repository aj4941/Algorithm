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
    ll n, a, b; cin >> n >> a >> b;
    vector<tuple<ll, ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        v.push_back({ abs(x - y), x, y });
    }

    sort(v.rbegin(), v.rend());

    ll ans = 0;

    for (auto to : v)
    {
        ll x = get<1>(to), y = get<2>(to);
        if (x < y)
        {
            if (a > 0) a--, ans += x;
            else b--, ans += y;
        }
        else
        {
            if (b > 0) b--, ans += y;
            else a--, ans += x;
        }
    }

    cout << ans;
}