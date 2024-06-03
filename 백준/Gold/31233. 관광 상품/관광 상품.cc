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
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;

    for (int i = 1; i < n; i++)
    {
        ll res = min(a[i], a[i - 1]);
        ans = max(ans, res);
    }

    for (int i = 2; i < n; i++)
    {
        ll res = min(a[i], a[i - 2]);
        ans = max(ans, res);
    }

    cout << ans;
}