#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000000

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int R, C, m; cin >> R >> C >> m;
	vector<pair<int, pii>> v[102][102];
	for (int i = 0; i < m; i++)
	{
		int r1, c1, s1, d1, z1;
		cin >> r1 >> c1 >> s1 >> d1 >> z1;
		v[r1][c1].push_back({ z1, { s1, d1 } });
	}
	if (m == 0)
	{
		cout << 0;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			if (v[j][i].size())
			{
				ans += v[j][i][0].first;
				auto it = v[j][i][0];
				v[j][i].erase(v[j][i].begin());
				break;
			}
		}
		vector<pair<int, pii>> nv[102][102];
		for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++)
		{
			for (auto to : v[r][c])
			{
				int x = r, y = c;
				int z = to.first, s = to.second.first, d = to.second.second;
				int S = s;
				if (d == 1 || d == 2)
				{
					s %= ((R - 1) * 2);
					if (d == 1)
					{
						int dx = x - 1;
						x -= min(dx, s); s -= min(dx, s);
						if (x == 1) d = 2;
						x += min(R - 1, s); s -= min(R - 1, s);
						if (x == R) d = 1;
						x -= min(R - 1, s); s -= min(R - 1, s);
					}
					else
					{
						int dx = R - x;
						x += min(dx, s); s -= min(dx, s);
						if (x == R) d = 1;
						x -= min(R - 1, s); s -= min(R - 1, s);
						if (x == 1) d = 2;
						x += min(R - 1, s); s -= min(R - 1, s);
					}
				}
				else
				{
					s %= ((C - 1) * 2);
					if (d == 3)
					{
						int dy = C - y;
						y += min(dy, s); s -= min(dy, s);
						if (y == C) d = 4;
						y -= min(C - 1, s); s -= min(C - 1, s);
						if (y == 1) d = 3;
						y += min(C - 1, s); s -= min(C - 1, s);
					}
					else
					{
						int dy = y - 1;
						y -= min(dy, s); s -= min(dy, s);
						if (y == 1) d = 3;
						y += min(C - 1, s); s -= min(C - 1, s);
						if (y == C) d = 4;
						y -= min(C - 1, s); s -= min(C - 1, s);
					}
				}
				nv[x][y].push_back({ z, { S, d } });
			}
		}
		for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++)
		{
			sort(nv[r][c].rbegin(), nv[r][c].rend());
			v[r][c].clear();
			if (nv[r][c].size())
				v[r][c].push_back(nv[r][c][0]);
		}

	}
	cout << ans;
}