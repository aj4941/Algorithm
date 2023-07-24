#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 2000;
vector<int> g[N];
bool cache[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        g[i].push_back(x);
    }

    int ans = -1, ans_cnt = -1;

    for (int i = 1; i <= n; i++)
    {
        memset(cache, false, sizeof cache);
        queue<int> q; q.push(i); cache[i] = true;
        int cnt = 0;
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            cnt++;
            for (int nv : g[v])
            {
                if (cache[nv]) continue;
                q.push(nv); cache[nv] = true;
            }
        }

        if (ans_cnt < cnt)
        {
            ans = i;
            ans_cnt = cnt;
        }
    }
    cout << ans;
}