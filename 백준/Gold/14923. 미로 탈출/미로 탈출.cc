#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 2000;
int a[N][N];
int dist[N][N][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dist, -1, sizeof dist);
	int n, m; cin >> n >> m;
	int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> a[i][j];

	queue<pair<pii, int>> q;
	q.push({ { sx, sy }, 0 }); dist[sx][sy][0] = 0;
	while (!q.empty())
	{
		auto to = q.front();
		int x = to.first.first, y = to.first.second, c = to.second; q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (a[nx][ny] == 0)
			{
				if (dist[nx][ny][c] == -1 ||
					dist[nx][ny][c] > dist[x][y][c] + 1)
				{
					q.push({ { nx, ny }, c });
					dist[nx][ny][c] = dist[x][y][c] + 1;
				}
			}
			else if (c == 0)
			{
				if (dist[nx][ny][c + 1] == -1 ||
					dist[nx][ny][c + 1] > dist[x][y][c] + 1)
				{
					q.push({ { nx, ny }, c + 1 });
					dist[nx][ny][c + 1] = dist[x][y][c] + 1;
				}
			}
		}
	}

	int ans = 1e9;
	if (dist[ex][ey][0] != -1) ans = min(ans, dist[ex][ey][0]);
	if (dist[ex][ey][1] != -1) ans = min(ans, dist[ex][ey][1]);
	if (ans == 1e9) ans = -1;
	cout << ans;
}