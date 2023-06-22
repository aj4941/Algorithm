#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll g, l; cin >> g >> l;
    ll val = l / g;

    ll ans_a = -1, ans_b = -1, sum = 1e18;
    for (ll a = 1; a <= 1e5; a++)
    {
        if (val % a) continue;
        ll b = val / a;

        if (gcd(a, b) == 1)
        {
            if (sum > a * g + b * g)
            {
                sum = a * g + b * g;
                ans_a = a * g, ans_b = b * g;
            }
        }
    }

    cout << ans_a << ' ' << ans_b;
}