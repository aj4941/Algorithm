#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
map<string, string> mp;
map<string, bool> cache;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll tc = 0;
    while (true)
    {
        int n; cin >> n;
        if (n == 0) break;
        tc++; mp.clear(); cache.clear();
        for (int i = 0; i < n; i++)
        {
            string s, t; cin >> s >> t;
            mp[s] = t;
        }

        ll ans = 0;

        for (auto to : mp)
        {
            if (cache.count(to.first)) continue;
            cache[to.first] = true;
            queue<string> q; q.push(to.first);
            while (!q.empty())
            {
                string v = q.front(); q.pop();
                string nv = mp[v];
                if (cache.count(nv)) continue;
                q.push(nv); cache[nv] = true;
            }

            ans++;
        }

        cout << tc << ' ' << ans << "\n";
    }
}