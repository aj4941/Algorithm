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
map<int, int> mp;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll l = 0, r = 1e15;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += mid / a[i];

        if (cnt >= m) r = mid;
        else l = mid;
    }

    cout << r;
}