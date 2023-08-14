#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c; cin >> c;
        vector<int> v;
        for (int j = 0; j < 12; j++)
        {
            int x; cin >> x;
            v.push_back(x);
        }

        int ans = 0;

        for (int x1 = 1; x1 < 11; x1++) for (int x2 = x1; x2 < 11; x2++)
        {
            int mn = 1e9;
            for (int j = x1; j <= x2; j++)
                mn = min(mn, v[j]);
            if (mn > v[x1 - 1] && mn > v[x2 + 1])
                ans++;
        }

        cout << c << ' ' << ans << "\n";
    }
}