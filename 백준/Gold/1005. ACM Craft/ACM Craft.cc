#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 1002;
vector<int> g[N];
int w[N], indegree[N], ans[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			ans[i] = 0;
			g[i].clear();
		}
		for (int i = 1; i <= n; i++) cin >> w[i];
		for (int i = 0; i < k; i++)
		{
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			indegree[v]++;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
				ans[i] = w[i];
			}
		}

		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int nv : g[v])
			{
				ans[nv] = max(ans[nv], ans[v] + w[nv]);
				indegree[nv]--;

				if (indegree[nv] == 0)
					q.push(nv);
			}
		}

		int x; cin >> x;
		cout << ans[x] << "\n";
	}
}