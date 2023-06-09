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
const int N = 120;
int n, m, x, y, ex, ey;
string s[N];
bool flag = false;
int dist[N][N][6];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> m >> n;
	memset(dist, -1, sizeof dist);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'C' && !flag)
			{
				flag = true;
				x = i, y = j;
			}
			else if (s[i][j] == 'C')
				ex = i, ey = j;
		}
	}

	deque<pair<pii, pii>> dq;

	for (int i = 0; i < 4; i++)
	{
		dq.push_back({ { x, y }, { i, 0 } });
		dist[x][y][i] = 0;
	}

	while (!dq.empty())
	{
		auto to = dq.front(); dq.pop_front();
		int x = to.first.first, y = to.first.second, c = to.second.first, d = to.second.second;
		if (dist[x][y][c] != d) continue;
		for (int i = 0; i < 4; i++)
		{
			int w = (c == i) ? 0 : 1;
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (s[nx][ny] == '*') continue;
			if (dist[nx][ny][i] == -1 || dist[x][y][c] + w < dist[nx][ny][i]) 
			{
				int nd = dist[x][y][c] + w;
				dist[nx][ny][i] = nd;
				if (w == 0) dq.push_front({ { nx, ny }, { i, nd } });
				else dq.push_back({ { nx, ny }, { i, nd } });
			}
		}
	}

	int ans = 1e9;

	for (int i = 0; i < 4; i++)
	{
		if (dist[ex][ey][i] == -1) continue;
		ans = min(ans, dist[ex][ey][i]);
	}
	
	cout << ans;
}