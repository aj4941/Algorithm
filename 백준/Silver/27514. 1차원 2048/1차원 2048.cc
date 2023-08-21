#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> mp;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    for (ll num = 1; num <= (1ll << 61); num *= 2)
    {
        mp[num * 2] += mp[num] / 2;
        mp[num] %= 2;
    }

    ll ans = 0;

    for (auto to : mp)
    {
        if (to.second > 0)
            ans = max(ans, to.first);
    }

    cout << ans;
}