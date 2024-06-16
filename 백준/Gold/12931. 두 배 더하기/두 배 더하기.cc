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
    ll n; cin >> n;
    vector<ll> a(n);
    ll cnt = 0, mx = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x; cin >> x;
        ll cur = 0;
        while (x > 0)
        {
            if (x % 2) cnt++, x--;
            else x /= 2, cur++;
        }

        mx = max(mx, cur);
    }

    cout << cnt + mx;
}