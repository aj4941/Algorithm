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
    vector<pii> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;

    int ans = 0;

    for (int bit = 1; bit < (1 << m); bit++)
    {
        int days = 0, page = 0;
        for (int i = 0; i < m; i++)
        {
            if (bit & (1 << i))
            {
                days += a[i].first;
                page += a[i].second;
            }
        }

        if (days <= n)
            ans = max(ans, page);
    }

    cout << ans;
}