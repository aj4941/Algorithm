#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 200;
ll a[N][N];
ll dist[N][N][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dist, -1, sizeof dist);
	ll n, m, t; cin >> n >> m >> t;
	for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++)
		cin >> a[i][j];

	dist[0][0][0] = 0;
	queue<tl> q; q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		auto to = q.front(); q.pop();
		ll x = get<0>(to), y = get<1>(to), k = get<2>(to);
		ll d = dist[x][y][k];
		for (ll i = 0; i < 4; i++)
		{
			ll nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny][k] != -1) continue;
			if (a[nx][ny] == 2)
			{
				dist[nx][ny][1] = d + 1;
				q.push({ nx, ny, 1 });
			}
			else if (a[nx][ny] == 1)
			{
				if (k == 0) continue;
				dist[nx][ny][k] = d + 1;
				q.push({ nx, ny, k });
			}
			else
			{
				dist[nx][ny][k] = d + 1;
				q.push({ nx, ny, k });
			}
		}
	}

	ll ans = 1e9;
	if (dist[n - 1][m - 1][0] != -1) ans = dist[n - 1][m - 1][0];
	if (dist[n - 1][m - 1][1] != -1) ans = min(ans, dist[n - 1][m - 1][1]);

	if (ans == 1e9 || ans > t) cout << "Fail";
	else cout << ans;
}