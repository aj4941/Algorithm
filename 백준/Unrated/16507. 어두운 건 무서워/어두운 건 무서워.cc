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
const int N = 2002;
int a[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> a[i][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			a[i][j] += a[i][j - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			a[i][j] += a[i - 1][j];
	}

	for (int i = 0; i < q; i++)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int sum = a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
		int div = (x2 - x1 + 1) * (y2 - y1 + 1);
		cout << sum / div << "\n";
	}
}