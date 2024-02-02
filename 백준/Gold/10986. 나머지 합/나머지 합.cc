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
const ll N = 1002;
ll a[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, m; cin >> n >> m;
    ll sum = 0, ans = 0;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin >> x;
        sum += x;
        ans += a[sum % m];
        a[sum % m]++;
        if (sum % m == 0) ans++;
    }

    cout << ans;
}