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
pii dist[60][60];
string s[60];
int n, m;
int sx, sy, ex, ey;

bool cmp(pii a, pii b) // a < b ? true : false
{
	if (a.first != b.first)
		return a.first < b.first;

	return a.second < b.second;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'S') sx = i, sy = j;
			if (s[i][j] == 'F') ex = i, ey = j;
			dist[i][j] = pii(-1, -1);
		}
	}

	dist[sx][sy] = pii(0, 0);
	priority_queue<tuple<int, int, int, int>> pq;
	pq.push({ 0, 0, sx, sy });

	while (!pq.empty())
	{
		auto to = pq.top(); pq.pop();
		pii d = pii(-get<0>(to), -get<1>(to));
		int x = get<2>(to), y = get<3>(to);
		if (dist[x][y] != d) continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			int w1 = s[nx][ny] == 'g' ? 1 : 0, w2 = 0;

			if (s[nx][ny] == '.') // 비어있을 때 주변 탐색
			{
				for (int k = 0; k < 4; k++)
				{
					int nnx = nx + dx[k], nny = ny + dy[k];
					if (nnx < 0 || nny < 0 || nnx >= n || nny >= m) continue;
					if (s[nnx][nny] == 'g') w2 = 1;
				}
			}

			pii new_dist = pii(dist[x][y].first + w1, dist[x][y].second + w2);

			if (dist[nx][ny] == pii(-1, -1) || cmp(new_dist, dist[nx][ny]))
			{
				dist[nx][ny] = new_dist;
				pq.push({ -dist[nx][ny].first, -dist[nx][ny].second, nx, ny });
			}
		}
	}

	cout << dist[ex][ey].first << ' ' << dist[ex][ey].second;
}