#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> d[20];

int main(void)
{
    int n; cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 1; i <= n; i++)
    {
        int m; cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x, y; cin >> x >> y;
            d[i].push_back({ x, y });
        }
    }

    vector<int> p;
    for (int i = 1; i <= n; i++) p.push_back(i);

    int ans = 1e9;
    do {
        vector<int> nc = c;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = p[i];
            res += nc[cur];
            for (auto to : d[cur])
            {
                int x = to.first, y = to.second;
                nc[x] = max(1, nc[x] - y);
            }
        }
        ans = min(ans, res);
    } while (next_permutation(p.begin(), p.end()));

    cout << ans;
    return 0;
}