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
const int N = 60;
int n, m;
string s[N];
int dist[N][N][4][2][2];
queue<tl> q;
bool flag = false;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dist, -1, sizeof dist);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'S')
			{
				for (int k = 0; k < 4; k++)
				{
					dist[i][j][k][0][0] = 0;
					q.push({ i, j, k, 0, 0 });
				}
			}
			if (s[i][j] == 'C' && !flag)
			{
				s[i][j] = 'D';
				flag = true;
			}
		}
	}

	while (!q.empty())
	{
		auto to = q.front(); q.pop();
		int x = get<0>(to), y = get<1>(to), k = get<2>(to);
		int a = get<3>(to), b = get<4>(to);

		for (int nk = 0; nk < 4; nk++)
		{
			if (nk == k) continue;
			int nx = x + dx[nk], ny = y + dy[nk];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (s[nx][ny] == '#') continue;
			if (s[nx][ny] == 'C')
			{
				if (dist[nx][ny][nk][1][b] != -1) continue;
				q.push({ nx, ny, nk, 1, b });
				dist[nx][ny][nk][1][b] = dist[x][y][k][a][b] + 1;
			}
			else if (s[nx][ny] == 'D')
			{
				if (dist[nx][ny][nk][a][1] != -1) continue;
				q.push({ nx, ny, nk, a, 1 });
				dist[nx][ny][nk][a][1] = dist[x][y][k][a][b] + 1;
			}
			else
			{
				if (dist[nx][ny][nk][a][b] != -1) continue;
				q.push({ nx, ny, nk, a, b });
				dist[nx][ny][nk][a][b] = dist[x][y][k][a][b] + 1;
 			}
		}
	}

	int ans = 1e9;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (dist[i][j][k][1][1] != -1)
				ans = min(ans, dist[i][j][k][1][1]);
		}
	}

	if (ans == 1e9) ans = -1;
	cout << ans;
}