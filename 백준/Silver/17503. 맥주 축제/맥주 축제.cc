#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    vector<pll> v;
    for (int i = 0; i < k; i++)
    {
        ll x, y; cin >> x >> y;
        v.push_back({ x, y });
    }

    sort(v.rbegin(), v.rend());

    ll sum = 0;
    for (int i = 0; i < min(n, k); i++) // 선호도 제한 없음
        sum += v[i].first;

    if (sum < m)
    {
        cout << -1;
        return 0;
    }

    ll l = 0, r = 1e15;

    while (l + 1 < r) // (l, r]
    {
        ll mid = (l + r) / 2;
        ll res = 0, cnt = 0;
        for (int i = 0; i < k; i++)
        {
            if (v[i].second <= mid)
            {
                res += v[i].first;
                cnt++;
            }

            if (cnt == n)
                break;
        }

        if (res >= m && cnt == n) r = mid;
        else l = mid;
    }

    cout << r;
}