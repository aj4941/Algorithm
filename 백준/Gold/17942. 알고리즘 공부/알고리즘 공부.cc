#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100002;
int n, m, k;
vector<pii> g[N];
bool cache[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }

    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++)
        pq.push({ -a[i], i });

    int ans = 0;

    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        int val = -to.first, v = to.second;
        if (cache[v]) continue;
        ans = max(ans, val); cache[v] = true;
        m--;
        if (m == 0) break;
        for (auto to : g[v])
        {
            int nv = to.first, w = to.second;
            a[nv] -= w;
            pq.push({ -a[nv], nv });
        }
    }

    cout << ans;
}