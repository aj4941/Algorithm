#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 1, 1, 1, 1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        if (n == 1)
        {
            cout << 1 << "\n" << 1 << "\n";
            continue;
        }
        ll x = 0;
        for (ll i = 0; i <= 10; i++)
        {
            if (n & (1ll << i))
                x = i;
        }

        vector<ll> ans;

        for (ll i = (1ll << x);
            i <= min(n, ((1ll << x) + (1ll << (x - 1)) - 1)); i++)
            ans.push_back(i);

        for (ll i = (1ll << (x - 1)); i <= (1ll << x) - 1; i++)
            ans.push_back(i);

        cout << ans.size() << "\n";
        sort(ans.begin(), ans.end());
        for (auto to : ans)
            cout << to << ' ';
        cout << "\n";
    }
}