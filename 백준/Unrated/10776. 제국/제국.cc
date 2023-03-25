#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 3002;
int k, n, m, A, B;
vector<ti> g[N];
int dist[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dist, -1, sizeof dist);
	cin >> k >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, t, h; cin >> a >> b >> t >> h;
		g[a].push_back({ b, t, h });
		g[b].push_back({ a, t, h });
	}

	cin >> A >> B;

	priority_queue<ti> pq; // (시간, v, 깎임) 
	pq.push({ 0, A, 0 }); dist[A][0] = 0;
	int ans = 1e9; 
	while (!pq.empty())
	{
		auto to = pq.top(); pq.pop();
		int t = -get<0>(to), v = get<1>(to), c = get<2>(to);
		if (v == B)
		{
			ans = min(ans, dist[v][c]);
			continue;
		}
		if (dist[v][c] != t) continue;
		for (auto too : g[v])
		{
			int nv = get<0>(too), nt = get<1>(too), nc = get<2>(too) + c;
			if (nc >= k) continue;
			if (dist[nv][nc] == -1 || dist[v][c] + nt < dist[nv][nc])
			{
				dist[nv][nc] = dist[v][c] + nt;
				pq.push({ -dist[nv][nc], nv, nc });
			}
		}
	}

	if (ans == 1e9) ans = -1;
	cout << ans;
}