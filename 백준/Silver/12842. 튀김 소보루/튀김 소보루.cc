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
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100002;
ll n, s, m;
ll a[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> s >> m;
    for (ll i = 1; i <= m; i++) cin >> a[i];

    ll cnt = n - s;
    if (cnt <= m)
    {
        cout << cnt;
        return 0;
    }

    cnt -= m;

    ll l = 0, r = 1e9;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll val = 0;
        for (int i = 1; i <= m; i++)
            val += mid / a[i];

        if (val >= cnt) r = mid;
        else l = mid;
    }

    // cout << r << endl;

    for (ll i = 1; i <= m; i++)
        cnt -= (r - 1) / a[i];

    for (ll i = 1; i <= m; i++)
    {
        if (r % a[i] == 0) cnt--;

        if (cnt == 0)
        {
            cout << i;
            return 0;
        }
    }
}