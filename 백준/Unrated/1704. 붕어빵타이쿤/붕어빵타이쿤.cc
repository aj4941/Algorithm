#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n, m;
int a[20][20], b[20][20], res[20][20];
vector<int> ans;
int ans_cnt = 1e9;

void calc(int x, int y)
{
	res[x][y] = 1;
	b[x][y] = 1 - b[x][y];
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		b[nx][ny] = 1 - b[nx][ny];
	}
}

void copy()
{
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++)
			b[i][j] = a[i][j];
}

bool check()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] == 1)
				return false;
		}
	}
	return true;
}

void insert() 
{

	int cnt = 0;
	vector<int> tmp;
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
	{
		tmp.push_back(res[i][j]);
		cnt += res[i][j];
	}

	if (ans.empty() || cnt < ans_cnt)
	{
		ans = tmp;
		ans_cnt = cnt;
	}
	else if (ans_cnt == cnt && tmp < ans)
		ans = tmp;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	for (int bit = 0; bit < (1 << n); bit++)
	{
		copy(); memset(res, 0, sizeof res);
		for (int i = 0; i < n; i++)
		{
			if (bit & (1 << i))
				calc(0, i);
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (b[i - 1][j] == 1)
					calc(i, j);
			}
		}

		if (check()) 
			insert();
	}

	if (ans.empty())
		cout << "IMPOSSIBLE";
	else
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << ans[i * n + j] << ' ';
			cout << "\n";
		}
	}
}