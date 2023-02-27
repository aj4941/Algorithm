#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 120;
int g[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		g[b][a] = 1; // 가벼운 것이 먼저 나오도록
	}

	for (int k = 1; k <= n; k++)
	{
		for (int a = 1; a <= n; a++) for (int b = 1; b <= n; b++)
		{
			if (g[a][k] && g[k][b])
				g[a][b] = 1;
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = n;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (g[j][i]) l++; // 자신보다 가벼운 것의 개수
			if (g[i][j]) r--; // 자신보다 무거운 것의 개수
		}

		if (l <= (n + 1) / 2 && (n + 1) / 2 <= r) continue;
		ans++;
	}

	cout << ans;
}