#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[6] = { 1, 1, 1, -1, -1, -1 };
int dy[6] = { 1, -1, 0, 0, -1, 1 };
#define MOD 1000000007
const int N = 20002;
int dfs_num[N], dfs_min[N], scc_num[N], ans[N];
bool finished[N], cache[N];
vector<vector<int>> scc;
vector<int> stk;
vector<int> g[N];
int n, m;
int dfs_cnt = 1;

int num(int x) // 음수 들어올경우 -x + n 처리 (정점 2n개)
{
	if (x < 0) return -x + n;
	else return x;
}

int dfs(int v) // scc 구성
{
	dfs_num[v] = dfs_min[v] = dfs_cnt++;
	stk.push_back(v);

	for (int nv : g[v])
	{
		if (dfs_num[nv] == 0)
			dfs_min[v] = min(dfs_min[v], dfs(nv));
		else if (finished[nv] == false)
			dfs_min[v] = min(dfs_min[v], dfs_min[nv]);
	}

	if (dfs_min[v] == dfs_num[v])
	{
		scc.push_back({});
		while (true)
		{
			int tv = stk.back(); stk.pop_back();
			scc.back().push_back(tv);
			scc_num[tv] = scc.size() - 1;
			finished[tv] = true;
			if (tv == v) break;
		}
	}

	return dfs_min[v];
}

void dfs2(int s) // scc 위상 정렬
{
	cache[s] = true;
	for (int v : scc[s])
	{
		for (int nv : g[v])
		{
			int ns = scc_num[nv];
			if (cache[ns]) continue;
			dfs2(ns);
		}
	}
	stk.push_back(s);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(ans, -1, sizeof ans);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		g[num(-u)].push_back(num(v));
		g[num(-v)].push_back(num(u));
	}

	for (int i = 1; i <= 2 * n; i++)
	{
		if (dfs_num[i] == 0)
			dfs(i);
	}

	bool hasAns = true;

	for (int i = 1; i <= n; i++) // 2-cnf 성립 여부
	{
		if (scc_num[i] == scc_num[i + n])
			hasAns = false;
	}

	if (hasAns == false)
	{
		cout << 0;
		return 0;
	}

	// i != i + n 이라면 2 cnf 성립

	for (int i = 0; i < scc.size(); i++)
	{
		if (cache[i] == false)
			dfs2(i);
	}

	cout << 1 << "\n";

	while (stk.size() > 0) // 위상 정렬에 따라 논리값 배정
	{
		int s = stk.back(); stk.pop_back();
		int res = 0;

		for (int v : scc[s])
		{
			if (ans[v] != -1)
			{
				res = ans[v];
				break;
			}
		}

		for (int v : scc[s])
		{
			if (v <= n)
				ans[v] = res, ans[v + n] = 1 - res;
			else
				ans[v] = res, ans[v - n] = 1 - res;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}