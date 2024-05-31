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
    ll n, m, L; cin >> n >> m >> L;
    vector<ll> a; a.push_back(0);
    for (int i = 0; i < m; i++)
    {
        ll x; cin >> x;
        a.push_back(x);
    }
    a.push_back(L);

    for (int i = 0; i < n; i++)
    {
        ll val; cin >> val;
        ll l = 0, r = 1e15;
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            ll cnt = 0, len = 0;
            for (int i = 1; i < a.size(); i++)
            {
                len += a[i] - a[i - 1];
                if (len >= mid)
                {
                    cnt++;
                    len = 0;
                }
            }

            if (cnt >= val + 1) l = mid;
            else r = mid;
        }

        cout << l << "\n";
    }
}