#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[6] = { 1, 1, 0, 0, -1, -1 };
int dy[6] = { 1, -1, -1, 1, -1, 1 };
#define MOD 1000000007
int n, m;
int board[120][120];
int cnt[2], id[111][111][2], match[12000];
vector<int> g[12000];
bool cache[12000];

void makeGroup(int dir)
{
	int x, y;
	cnt[dir] = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (board[i][j] || id[i][j][dir]) continue;
		x = i, y = j;
		id[i][j][dir] = ++cnt[dir];
		while (true)
		{
			x += dx[dir], y += dy[dir];
			if (x < 1 || y < 1 || x > n || y > n) break;
			if (board[x][y] || id[x][y][dir]) break;
			id[x][y][dir] = cnt[dir];
		}
	}
}

bool dfs(int v)
{
	cache[v] = true;
	for (int nv : g[v])
	{
		if (cache[match[nv]]) continue;
		if (match[nv] == 0 || dfs(match[nv]))
		{
			match[nv] = v;
			return true;
		}
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		board[a][b] = 1;
	}
	makeGroup(0); makeGroup(1);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (board[i][j]) continue;
		int aid = id[i][j][0], bid = id[i][j][1] + cnt[0];
		g[aid].push_back(bid);
	}
	for (int i = 1; i <= cnt[0]; i++)
	{
		memset(cache, false, sizeof cache);
		if (dfs(i)) ans++;
	}
	cout << ans;
}