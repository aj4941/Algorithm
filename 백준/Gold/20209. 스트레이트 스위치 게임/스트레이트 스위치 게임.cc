#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll n, k;
ll prv[10];
vector<ll> c[10];
vector<ll> a;
ll ans = 1e9;

void dfs(int idx)
{
    if (idx == k + 1)
    {
        ll res = 0;
        vector<ll> sa = a;
        for (ll i = 1; i <= k; i++)
        {
            ll cnt = prv[i]; res += cnt;
            for (auto to : c[i])
            {
                sa[to] += cnt * i;
                sa[to] %= 5;
            }
        }

        bool hasAns = true;
        for (ll i = 2; i <= n; i++)
        {
            if (sa[1] != sa[i])
                hasAns = false;
        }

        if (hasAns)
            ans = min(ans, res);

        return;
    }

    for (int i = 0; i <= 4; i++)
    {
        prv[idx] = i;
        dfs(idx + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;

    a.push_back(0);

    for (ll i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        a.push_back(x);
    }

    for (ll i = 1; i <= k; i++)
    {
        ll cnt; cin >> cnt;
        for (ll j = 0; j < cnt; j++)
        {
            ll x; cin >> x;
            c[i].push_back(x);
        }
    }

    dfs(1);

    if (ans == 1e9) ans = -1;
    cout << ans;
}