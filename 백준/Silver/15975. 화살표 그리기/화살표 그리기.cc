#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll N = 100002;
vector<ll> v[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i < N; i++) v[i].push_back(-1e18);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y; // (좌표, 색깔)
        v[y].push_back(x);
    }
    for (int i = 1; i < N; i++)
    {
        v[i].push_back(1e18);
        sort(v[i].begin(), v[i].end());
    }

    ll ans = 0;

    for (int i = 1; i < N; i++)
    {
        if (v[i].size() <= 3) continue;
        for (int j = 1; j < v[i].size() - 1; j++)
        {
            ll r1 = v[i][j] - v[i][j - 1];
            ll r2 = v[i][j + 1] - v[i][j];
            ans += min(r1, r2);
        }
    }

    cout << ans;
}