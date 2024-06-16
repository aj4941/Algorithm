#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    do {
        vector<ll> cnt(102); cnt[0] = 1;
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            res += a[i];
            cnt[res] = 1;
        }
        ll tmp = 0;
        for (ll i = 0; i < 50; i++)
        {
            if (cnt[i] && cnt[50 + i])
                tmp++;
        }
        ans = max(ans, tmp);
    } while (next_permutation(a.begin(), a.end()));

    cout << ans;
}