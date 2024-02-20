#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll N = 200005;
ll res[N], asum[N];
vector<pll> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        ll a, x; cin >> a >> x;
        v.push_back({ x, a });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        res[i] = v[i].first * v[i].second;
        asum[i] = v[i].second;
    }

    for (int i = 1; i < n; i++)
    {
        res[i] += res[i - 1];
        asum[i] += asum[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        ll x; cin >> x;
        ll idx = upper_bound(v.begin(), v.end(), pll(x, 1e15)) - v.begin();
        int lidx = idx - 1, ridx = idx;
        ll lsum = asum[lidx] * x - res[lidx];
        ll rsum = res[n - 1] - res[ridx - 1] - (asum[n - 1] - asum[ridx - 1]) * x;
        // cout << lsum << ' ' << rsum << endl;
        cout << lsum + rsum << "\n";
    }
}