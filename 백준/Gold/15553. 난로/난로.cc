#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> a(n), diff;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = a.back() - a.front() + 1;

    for (int i = 1; i < n; i++)
        diff.push_back(a[i] - a[i - 1]);

    sort(diff.rbegin(), diff.rend());

    for (int i = 0; i < m - 1; i++)
        ans -= diff[i] - 1;

    cout << ans;
}