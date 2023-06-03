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
const int N = 3002;
int a[N][N];
int n, m;
bool cache[N][N][5];
vector<vector<int>> mv = { { 0, 3, 2, 1 }, { 2, 1, 0, 3 },
							{ 1, 0, 3, 2 }, { 3, 2, 1, 0 } };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	queue<pair<pii, int>> q;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		cin >> a[i][j];
		if (a[i][j] == 9)
		{
			for (int k = 0; k < 4; k++)
			{
				q.push({ { i, j }, k });
				cache[i][j][k] = true;
			}
		}

		a[i][j]--;
	}

	while (!q.empty())
	{
		auto to = q.front(); q.pop();
		int x = to.first.first, y = to.first.second, c = to.second;
		int nx = x + dx[c], ny = y + dy[c];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (a[nx][ny] == 8) continue;

		if (a[nx][ny] != -1)
		{
			int nc = mv[a[nx][ny]][c];
			if (cache[nx][ny][nc]) continue;
			q.push({ { nx, ny }, nc });
			cache[nx][ny][nc] = true;
		}
		else
		{
			if (cache[nx][ny][c]) continue;
			q.push({ { nx, ny }, c });
			cache[nx][ny][c] = true;
		}
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		bool flag = false;
		for (int k = 0; k < 4; k++)
		{
			if (cache[i][j][k])
				flag = true;
		}

		if (flag)
			ans++;
	}
	cout << ans;
}