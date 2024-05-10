#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, -1, 1 };
ll n, m;
ll cnt[20], ccnt[20];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        for (int j = 0; j <= 15; j++)
        {
            if (x & (1ll << j))
                cnt[j]++;
        }
    }

    ll l = 0, r = 1e15;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        for (int i = 0; i < 20; i++) ccnt[i] = cnt[i];
        for (int i = 0; i < m; i++)
        {
            ll val = mid;
            for (int j = 15; j >= 0; j--)
            {
                ll inc = val / (1ll << j);
                ll mcount = min(inc, ccnt[j]);
                val -= mcount * (1ll << j); ccnt[j] -= mcount;
            }
        }
        bool flag = true;
        for (int j = 0; j <= 15; j++)
        {
            if (ccnt[j] > 0)
                flag = false;
        }

        if (flag) r = mid;
        else l = mid;
    }

    cout << r;
}