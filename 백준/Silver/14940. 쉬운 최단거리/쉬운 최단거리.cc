#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll a[1002][1002];
ll dist[1002][1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dist, -1, sizeof dist);
	queue<pll> q;
	ll n, m; cin >> n >> m;
	for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++)
	{
		cin >> a[i][j];
		if (a[i][j] == 2)
		{
			q.push({ i, j });
			dist[i][j] = 0;
		}
	}

	while (!q.empty())
	{
		ll x = q.front().first, y = q.front().second; q.pop();
		for (ll i = 0; i < 4; i++)
		{
			ll nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny] != -1 || a[nx][ny] == 0) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			if (a[i][j] == 0) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << "\n";
	}
}