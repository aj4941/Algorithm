#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<vector<int>> g(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int j; cin >> j;
            g[i].push_back(j);
        }
        vector<int> cache(n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!cache[i])
            {
                cnt++;
                queue<int> q; q.push(i);
                while (!q.empty())
                {
                    int v = q.front(); q.pop();
                    cache[v] = 1;
                    for (int nv : g[v])
                    {
                        if (!cache[nv])
                            q.push(nv);
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}