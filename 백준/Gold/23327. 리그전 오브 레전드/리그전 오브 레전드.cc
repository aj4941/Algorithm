#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll N = 200002;
ll psum[N], sum[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n; i >= 1; i--)
    {
        if (i == n) psum[i] = a[i];
        else psum[i] = psum[i + 1] + a[i];
    }

    ll total = 0;

    for (int i = 1; i <= n - 1; i++)
        total += a[i] * psum[i + 1];

    sum[1] = total;

    for (int i = 2; i <= n - 1; i++)
        sum[i] = sum[i - 1] - a[i - 1] * psum[i];

    for (int i = 0; i < q; i++)
    {
        ll l, r; cin >> l >> r;
        ll lsum = psum[l] - psum[r + 1];
        ll rsum = psum[r + 1];

        cout << sum[l] - (lsum * rsum) - sum[r + 1] << "\n";
    }
}