#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, k, s;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> s;
    vector<pii> l, r;

    for (int i = 0; i < n; i++)
    {
        int pos, cnt; cin >> pos >> cnt;
        if (pos < s) l.push_back({ pos, cnt });
        else r.push_back({ pos, cnt });
    }

    sort(l.rbegin(), l.rend());
    sort(r.begin(), r.end());
    ll ans = 0;

    while (l.size())
    {
        int cnt = 0, pos = l.back().first;
        while (true)
        {
            int mn = min(l.back().second, k - cnt);
            l.back().second -= mn, cnt += mn;
            if (l.back().second == 0) l.pop_back();
            if (l.size() == 0 || k == cnt) break;
        }

        ans += 2 * abs(pos - s);
    }

    while (r.size())
    {
        int cnt = 0, pos = r.back().first;
        while (true)
        {
            int mn = min(r.back().second, k - cnt);
            r.back().second -= mn, cnt += mn;
            if (r.back().second == 0) r.pop_back();
            if (r.size() == 0 || k == cnt) break;
        }

        ans += 2 * abs(pos - s);
    }

    cout << ans;
}