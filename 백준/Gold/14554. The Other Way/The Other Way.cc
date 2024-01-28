// 지문이 짧으므로 생략





























// 다익스트라 진행 중에 경우의 수를 구할 수 있음
// dist[nv] = dist[v] + w 이면 ans[nv] += ans[v] : v에서 나온 경우의 수가 모두 들어가는 것
// dist[nv] > dist[v] + w 이면 ans[nv] = ans[v] : nv의 경우의 수가 최소거리가 갱신되었으므로 ans[v]로 갱신되어야 함
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 100002;
const ll inf = 1000000009;
ll n, m, S, E;
vector<pll> g[N];
ll dist[N], ans[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> S >> E;
    for (ll i = 0; i <= n; i++) dist[i] = 1e18;
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    priority_queue<pll> pq; pq.push({ 0, S }); dist[S] = 0; ans[S] = 1;
    while (!pq.empty()) {
        ll d = -pq.top().first, v = pq.top().second; pq.pop();
        if (dist[v] != d) continue;
        for (auto to : g[v]) {
            ll nv = to.first, w = to.second;
            if (dist[nv] > dist[v] + w) {
                dist[nv] = dist[v] + w;
                pq.push({ -dist[nv], nv });
                ans[nv] = ans[v];
            }
            else if (dist[nv] == dist[v] + w) {
                ans[nv] += ans[v];
                ans[nv] %= inf;
            }
        }
    }

    cout << ans[E];
}