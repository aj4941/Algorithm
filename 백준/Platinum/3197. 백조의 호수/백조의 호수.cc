#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000007
string st[1502];
bool cache[1502][1502];
int p[2500000];

int find(int x)
{
	if (p[x] == x)
		return x;
	else
		return p[x] = find(p[x]);
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(cache, false, sizeof cache);
	queue<pii> q, sq;
	int r, c; cin >> r >> c;
	for (int i = 0; i <= r * c; i++) p[i] = i;
	vector<pii> pos;
	for (int i = 0; i < r; i++) cin >> st[i];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (st[i][j] == 'L')
				pos.push_back({ i, j });
			if (st[i][j] == '.' || st[i][j] == 'L')
			{
				q.push({ i, j });
				cache[i][j] = true;
			}
		}
	}
	int sx = pos[0].first, sy = pos[0].second;
	int ex = pos[1].first, ey = pos[1].second;
	int ans = 0;
	while (true)
	{
		int u = find(sx * c + sy), v = find(ex * c + ey);
		if (u == v)
		{
			cout << ans;
			return 0;
		}
		ans++;
		while (!q.empty())
		{
			auto to = q.front();
			int x = to.first, y = to.second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				int u = x * c + y, v = nx * c + ny;
				u = find(u), v = find(v);
				if (u != v)
					p[u] = v;

				if (cache[nx][ny] == true || st[nx][ny] != 'X') continue;
				st[nx][ny] = '.';
				sq.push({ nx, ny });
				cache[nx][ny] = true;
			}
		}

		while (!sq.empty())
		{
			auto to = sq.front();
			int x = to.first, y = to.second;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (st[nx][ny] == '.' || st[nx][ny] == 'L')
				{
					int u = x * c + y, v = nx * c + ny;
					u = find(u); v = find(v);
					p[u] = v;
				}
			}
			q.push(to); sq.pop();
		}
	}
	cout << ans;
}