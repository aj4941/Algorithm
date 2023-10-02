#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
int dx[8] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int N = 100002;
vector<int> g[N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[v].push_back(u);
    }

    int cv; cin >> cv;
    int ans = 0;
    queue<int> q; q.push(cv);
    vector<bool> cache(n + 1, false);
    cache[cv] = true;
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int nv : g[v])
        {
            if (cache[nv]) continue;
            q.push(nv); cache[nv] = true;
            ans++;
        }
    }

    cout << ans;
}