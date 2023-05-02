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
int n, m, k;
const int N = 100;
int a[N][N], sa[N][N];
vector<ti> q;
vector<int> p;

void solve(int x, int y, int c)
{
	for (int nc = 1; nc <= c; nc++)
	{
		int sx = x - nc, sy = y - nc;
		int val = a[sx][sy];
		for (int i = sx; i <= sx + 2 * nc - 1; i++) a[i][sy] = a[i + 1][sy];
		for (int j = sy; j <= sy + 2 * nc - 1; j++) a[sx + 2 * nc][j] = a[sx + 2 * nc][j + 1];
		for (int i = sx + 2 * nc; i >= sx + 1; i--) a[i][sy + 2 * nc] = a[i - 1][sy + 2 * nc];
		for (int j = sy + 2 * nc; j >= sy + 2; j--) a[sx][j] = a[sx][j - 1];
		a[sx][sy + 1] = val;
	}
}

void init() 
{
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		a[i][j] = sa[i][j];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		cin >> a[i][j];
		sa[i][j] = a[i][j];
	}

	for (int i = 0; i < k; i++)
	{
		int x, y, c; cin >> x >> y >> c; x--, y--;
		q.push_back({ x, y, c });
		p.push_back(i);
	}

	ll ans = 1e15;

	do {
		init();
		for (int i = 0; i < k; i++)
		{
			auto to = q[p[i]];
			int x = get<0>(to), y = get<1>(to), c = get<2>(to);
			solve(x, y, c);
		}

		for (int i = 0; i < n; i++)
		{
			ll sum = 0;
			for (int j = 0; j < m; j++)
				sum += a[i][j];

			ans = min(ans, sum);
		}

	} while (next_permutation(p.begin(), p.end()));

	cout << ans;
}