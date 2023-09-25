#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    ll res = 0;
    for (int i = 1; i < n; i++)
        res += abs(a[i].first - a[i - 1].first) + abs(a[i].second - a[i - 1].second);

    ll ans = 1e18;

    for (int i = 1; i < n - 1; i++)
    {
        ll r1 = abs(a[i - 1].first - a[i].first) + abs(a[i - 1].second - a[i].second);
        ll r2 = abs(a[i + 1].first - a[i].first) + abs(a[i + 1].second - a[i].second);
        ll r3 = abs(a[i - 1].first - a[i + 1].first) + abs(a[i - 1].second - a[i + 1].second);
        ans = min(ans, res - r1 - r2 + r3);
    }

    cout << ans;
}