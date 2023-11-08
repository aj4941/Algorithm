#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        ll n, k; cin >> n >> k;
        ll l = 0, r = 1e4;
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            if (k * (mid * (mid + 1) / 2) <= n - 1) l = mid;
            else r = mid;
        }
        ll x = l;
        ll pos = (x + 1) / 2 * k;
        if (x % 2 == 0) pos = -pos;
        char ch = (x % 2) ? 'L' : 'R';
        ll rm = n - 1 - k * (x * (x + 1) / 2);
        if (ch == 'L') pos -= rm;
        else pos += rm;

        cout << pos << ' ' << ch << "\n";
    }
}