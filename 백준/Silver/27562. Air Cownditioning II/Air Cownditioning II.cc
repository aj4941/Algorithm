#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 200;
int n, m;
ll cnt[N], pcnt[N];
ll a[N], b[N], p[N], mny[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll l, r, c; cin >> l >> r >> c;
        cnt[l] += c, cnt[r + 1] -= c;
    }

    for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];

    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> p[i] >> mny[i];

    ll ans = 1e18;

    for (int bit = 1; bit < (1 << m); bit++)
    {
        memset(pcnt, 0, sizeof pcnt);
        ll res = 0;
        for (int i = 0; i < m; i++)
        {
            if (bit & (1 << i))
            {
                pcnt[a[i]] += p[i];
                pcnt[b[i] + 1] -= p[i];
                res += mny[i];
            }
        }

        bool flag = true;

        for (int i = 1; i < N; i++)
        {
            pcnt[i] += pcnt[i - 1];
            if (pcnt[i] < cnt[i])
                flag = false;
        }

        if (flag)
            ans = min(ans, res);
    }

    cout << ans;
}