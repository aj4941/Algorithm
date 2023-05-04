#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 1020;
ll jdist[N][N], fdist[N][N];
int n, m;
vector<string> s;

void bfs(ll dist[N][N], vector<pii> v)
{
	queue<pii> q;

	for (auto to : v)
	{
		int x = to.first, y = to.second;
		q.push({ x, y }); dist[x][y] = 0;
	}

	while (!q.empty())
	{
		auto to = q.front(); q.pop();
		int x = to.first, y = to.second; 
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny] != -1) continue;
			if (s[nx][ny] == '#') continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(jdist, -1, sizeof jdist); memset(fdist, -1, sizeof fdist);
	cin >> n >> m;
	s.resize(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	
	vector<pii> fvec;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (s[i][j] == 'J')
		{
			vector<pii> tmp = { pii(i, j) };
			bfs(jdist, tmp);
		}
		if (s[i][j] == 'F')
			fvec.push_back({ i, j });
	}

	bfs(fdist, fvec);

	ll ans = 1e9;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
		{
			if (s[i][j] == '#') continue;
			if (jdist[i][j] == -1) continue;
			if (fdist[i][j] == -1) 
				ans = min(ans, jdist[i][j] + 1);
			else if (jdist[i][j] < fdist[i][j])
				ans = min(ans, jdist[i][j] + 1);
		}
	}
	
	if (ans == 1e9)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}

	cout << ans;
}