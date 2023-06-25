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
const int N = 50000;
int cnt[N * 3];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i] + N]++;
    }

    sort(a.begin(), a.end());
    ll ans = 0;

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
    {
        ll val = a[i] + a[j];
        ll res = cnt[-val + N];
        if (-val == a[i]) res--;
        if (-val == a[j]) res--;
        ans += res;
    }

    cout << ans / 3;
}