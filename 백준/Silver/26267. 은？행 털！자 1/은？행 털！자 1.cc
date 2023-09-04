#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    map<ll, ll> mp;
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x, y, c; cin >> x >> y >> c;
        mp[y - x] += c;
    }

    ll ans = 0;

    for (auto to : mp)
        ans = max(ans, to.second);

    cout << ans;
}