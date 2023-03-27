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
const int N = 1002;
vector<int> g[N];
int ans[N], indegree[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v); indegree[v]++;
	}

	queue<int> q, nq;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			ans[i] = 1;
		}
	}

	int cnt = 1;

	while (!q.empty()) 
	{
		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int nv : g[v])
			{
				indegree[nv]--;
				if (indegree[nv] == 0)
					nq.push(nv);
			}
		}

		cnt++;

		while (!nq.empty())
		{
			int nv = nq.front(); nq.pop();
			ans[nv] = cnt;
			q.push(nv);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}