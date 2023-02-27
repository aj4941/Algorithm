#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
bool cache[1002][1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	int k; cin >> k;

	if (k > n * m)
	{
		cout << 0;
		return 0;
	}

	cache[1][1] = true; k--;
	int ch = 0;
	int x = 1, y = 1;

	while (k > 0)
	{
		int nx = x + dx[ch], ny = y + dy[ch];
		if (nx <= 0 || ny <= 0 || nx > n || ny > m)
		{
			ch = (ch + 1) % 4;
			continue;
		}
		if (cache[nx][ny])
		{
			ch = (ch + 1) % 4;
			continue;
		}
		x = nx, y = ny; cache[x][y] = true; k--;
	}

	cout << x << ' ' << y;
}