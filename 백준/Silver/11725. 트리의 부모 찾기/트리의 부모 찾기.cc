#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
#define INF 101112987654321
#define M_PI 3.14159265358979323846
ll parent[100002];
ll n;
vector<vector<ll>> graph(100002);
bool visit[100002];

void dfs(ll v)
{
	visit[v] = true;
	for (ll to : graph[v])
	{
		if (!visit[to])
		{
			parent[to] = v;
			dfs(to);
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (ll i = 0; i < n - 1; i++)
	{
		ll u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	for (ll i = 2; i <= n; i++)
		cout << parent[i] << "\n";
}