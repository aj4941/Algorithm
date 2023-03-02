#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n, m;
string s[600];
int cache[600][600], cycle[600][600];
int a[600][600];

void dfs(int x, int y)
{
	// cout << x << ' ' << y << endl;
	cache[x][y] = 1;
	int nx = x + dx[a[x][y]], ny = y + dy[a[x][y]];
	if (nx < 0 || ny < 0 || nx >= n || ny >= m)
	{
		cache[x][y] = 2;
		return;
	}
	if (cache[nx][ny] == 0) dfs(nx, ny);
	else if (cache[nx][ny] == 1) cycle[x][y] = 1;

	if (cycle[nx][ny]) cycle[x][y] = 1;

	cache[x][y] = 2;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int c = -1;
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'L') c = 0;
			if (s[i][j] == 'R') c = 1;
			if (s[i][j] == 'U') c = 2;
			if (s[i][j] == 'D') c = 3;
			a[i][j] = c;
		}
	}
	
	int ans = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (cache[i][j] == 2 && cycle[i][j] == 0)
			ans++;
		else
		{
			dfs(i, j);
			if (cycle[i][j] == 0)
				ans++;
		}
	}

	cout << ans;
}