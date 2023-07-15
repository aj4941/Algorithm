#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 100;
vector<int> g[N];
int dist[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    while (true)
    {
        int x, y; cin >> x >> y;
        if (x == -1 && y == -1) break;
        g[x].push_back(y); g[y].push_back(x);
    }

    int ans_len = 1e9;
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        memset(dist, -1, sizeof dist);
        queue<int> q; q.push(i); dist[i] = 0;
        int mx_len = 0;
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            mx_len = max(mx_len, dist[v]);
            for (int nv : g[v])
            {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }

        if (mx_len < ans_len)
        {
            ans_len = mx_len;
            ans.clear(); ans.push_back(i);
        }
        else if (mx_len == ans_len)
            ans.push_back(i);
    }

    cout << ans_len << ' ' << ans.size() << "\n";
    for (auto to : ans) cout << to << ' ';
}