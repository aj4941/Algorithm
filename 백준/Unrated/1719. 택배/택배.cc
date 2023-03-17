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
const int N = 202;
int f[N][N], via[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (i != j)
			f[i][j] = 1e9;

		via[i][j] = j;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		f[u][v] = min(f[u][v], w);
		f[v][u] = min(f[v][u], w);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		{
			if (f[i][k] == 1e9 || f[k][j] == 1e9) continue;

			if (f[i][k] + f[k][j] < f[i][j])
			{
				f[i][j] = f[i][k] + f[k][j];
				via[i][j] = via[i][k];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) cout << "- ";
			else cout << via[i][j] << ' ';
		}
		cout << "\n";
	}
}