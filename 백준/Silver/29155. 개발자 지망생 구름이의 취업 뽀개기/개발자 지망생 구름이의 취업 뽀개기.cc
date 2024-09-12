#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };
vector<int> g[10];
vector<int> p(6);
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= 5; i++)
        cin >> p[i];

    for (int i = 0; i < n; i++)
    {
        int k, t; cin >> k >> t;
        g[k].push_back(t);
    }

    for (int i = 1; i <= 5; i++)
        sort(g[i].begin(), g[i].end());

    int ans = 0;

    for (int i = 1; i <= 5; i++)
    {
        int idx = 0;
        while (p[i] > 0)
        {
            if (idx == 0) ans += g[i][idx++];
            else
            {
                ans += g[i][idx] - g[i][idx - 1];
                ans += g[i][idx++];
            }
            p[i]--;
        }

        if (i < 5) ans += 60;
    }

    cout << ans;
}