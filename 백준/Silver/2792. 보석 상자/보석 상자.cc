#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 0;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];

    ll l = 0, r = 1e15;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (auto to : v)
            cnt += (to + mid - 1) / mid;

        if (cnt > n) l = mid;
        else r = mid;
    }

    cout << r;
}