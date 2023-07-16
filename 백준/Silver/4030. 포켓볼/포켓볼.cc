#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 100005;
map<ll, bool> mp;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i < N; i++)
        mp[i * (i + 1) / 2] = true;

    ll tc = 1;
    while (true)
    {
        ll a, b; cin >> a >> b;
        if (a == 0 && b == 0) break;
        ll ans = 0;
        for (ll i = 1; i < N; i++)
        {
            ll val = i * i;
            if (a < val && val < b)
            {
                if (mp.count(val - 1))
                    ans++;
            }
        }

        cout << "Case " << tc++ << ": " << ans << "\n";
    }
}