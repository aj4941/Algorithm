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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int m, n; cin >> m >> n;
	vector<string> s(m);
	for (int i = 0; i < m; i++) cin >> s[i];

	queue<pii> q;

	for (int j = 0; j < n; j++)
	{
		if (s[0][j] == '0')
		{
			q.push({ 0, j });
			s[0][j] = 'x';
		}
	}

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (s[nx][ny] == '1' || s[nx][ny] == 'x') continue;
			s[nx][ny] = 'x'; q.push({ nx, ny });
		}
	}

	bool hasAns = false;

	for (int j = 0; j < n; j++)
	{
		if (s[m - 1][j] == 'x')
			hasAns = true;
	}

	if (hasAns) cout << "YES";
	else cout << "NO";
}