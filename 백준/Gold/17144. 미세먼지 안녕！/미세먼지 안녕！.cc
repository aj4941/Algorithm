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
const ll N = 100;
ll a[N][N], tmp[N][N];
ll hx, lx;
bool flag = false;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, t; cin >> n >> m >> t;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		cin >> a[i][j];
		if (a[i][j] == -1 && !flag)
		{
			hx = i, lx = i + 1; 
			flag = true;
		}
	}

	for (int tm = 0; tm < t; tm++)
	{
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			tmp[i][j] = a[i][j];

		// 미세먼지 확산
		for (int x = 0; x < n; x++) for (int y = 0; y < m; y++)
		{
			if (a[x][y] == -1) continue; 
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k], ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (a[nx][ny] == -1) continue;
				tmp[nx][ny] += a[x][y] / 5;
				tmp[x][y] -= a[x][y] / 5;
			}
		}

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			a[i][j] = tmp[i][j];

		for (int i = hx - 1; i >= 1; i--) a[i][0] = a[i - 1][0];
		for (int j = 0; j <= m - 2; j++) a[0][j] = a[0][j + 1];
		for (int i = 0; i <= hx - 1; i++) a[i][m - 1] = a[i + 1][m - 1];
		for (int j = m - 1; j >= 2; j--) a[hx][j] = a[hx][j - 1];
		a[hx][1] = 0; 
		
		for (int i = lx + 1; i <= n - 2; i++) a[i][0] = a[i + 1][0];
		for (int j = 0; j <= m - 2; j++) a[n - 1][j] = a[n - 1][j + 1];
		for (int i = n - 1; i >= lx + 1; i--) a[i][m - 1] = a[i - 1][m - 1];
		for (int j = m - 1; j >= 2; j--) a[lx][j] = a[lx][j - 1];
		a[lx][1] = 0;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (a[i][j] == -1) continue;
		ans += a[i][j];
	}

	cout << ans;
}