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
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
pii cache[1002][1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, l, r; cin >> n >> m >> l >> r;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cache[i][j] = pii(-1, -1);

	int px = -1, py = -1;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '2')
				px = i, py = j;
		}
	}

	deque<pii> q; q.push_back({ px, py });
	cache[px][py] = pii(0, 0);

	while (!q.empty())
	{
		auto to = q.front();
		int x = to.first, y = to.second; q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (a[nx][ny] == '1' || cache[nx][ny] != pii(-1, -1)) continue;
			pii res = cache[x][y];
			if (i == 2) res.first++;
			if (i == 3) res.second++;
			cache[nx][ny] = res;

			if (cache[x][y] == cache[nx][ny])
				q.push_front({ nx, ny });
			else
				q.push_back({ nx, ny });
		}
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (cache[i][j] == pii(-1, -1)) continue;
		pii res = cache[i][j];
		if (res.first <= l && res.second <= r) ans++;
	}

	cout << ans;
}