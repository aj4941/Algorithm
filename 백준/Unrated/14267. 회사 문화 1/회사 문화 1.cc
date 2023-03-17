#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100050;
int n, m; 
vector<int> g[N];
pii ett[N];
int ett_cnt = 1, psum[N];

void dfs(int v, int p)
{
	ett[v].first = ett_cnt++;
	for (int nv : g[v])
	{
		if (nv == p) continue;
		dfs(nv, v);
	}
	ett[v].second = ett_cnt - 1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		if (i == 1) continue;
		g[x].push_back(i);
	}

	dfs(1, 0);

	for (int i = 0; i < m; i++)
	{
		int x, w; cin >> x >> w;
		psum[ett[x].first] += w; psum[ett[x].second + 1] -= w;
	}

	for (int i = 1; i <= n; i++)
		psum[i] += psum[i - 1];

	for (int i = 1; i <= n; i++)
		cout << psum[ett[i].first] << ' ';
}