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
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        int c; cin >> c;
        for (int j = 0; j < c; j++)
        {
            ll x; cin >> x;
            v[i] |= (1ll << x);
        }
    }

    int m; cin >> m;

    for (int i = 0; i < m; i++)
    {

        int c; cin >> c;
        ll bit = 0;
        for (int j = 0; j < c; j++)
        {
            ll x; cin >> x;
            bit |= (1ll << x);
        }

        int ans = 0;

        for (int j = 0; j < n; j++)
        {
            if ((bit | v[j]) == bit)
                ans++;
        }

        cout << ans << "\n";
    }
}