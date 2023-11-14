#include <bits/stdc++.h>
using namespace std;
const int N = 1000030;
typedef pair<int, int> pii;
int x;
pii a[N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true)
    {
        int n, k; cin >> n >> k;
        if (n == 0 && k == 0) return 0;
        vector<vector<int>> g; g.push_back({});
        vector<int> v; cin >> x; v.push_back(x);
        g.back().push_back(x);
        for (int i = 1; i < n; i++)
        {
            cin >> x; v.push_back(x);
            if (g.back().back() + 1 == x)
                g.back().push_back(x);
            else
            {
                g.push_back({});
                g.back().push_back(x);
            }
        }

        int r = g[0][0]; a[r] = { 0, 0 };
        queue<int> q; q.push(r);

        for (int i = 1; i < g.size(); i++)
        {
            int p = q.front(); q.pop();
            for (auto to : g[i])
            {
                a[to] = { p, a[p].second + 1 };
                q.push(to);
            }
        }

        int ans = 0;

        for (auto to : v)
        {
            if (a[k].first == to) continue;
            int to_p = a[to].first, k_p = a[k].first;
            if (to_p != k_p && a[to_p].first == a[k_p].first)
            {
                // cout << "num : " << to << endl;
                ans++;
            }
        }

        cout << ans << "\n";
    }
}