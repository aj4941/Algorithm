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
const int N = 1200;
string s[N];
int n, m, p;
int a[N][N], ans[20];
queue<ti> q[20], nq[20];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> p;
	vector<int> v(p + 1);

	for (int i = 1; i <= p; i++) cin >> v[i];

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.') a[i][j] = 0;
			else if (s[i][j] == '#') a[i][j] = -1;
			else 
			{
				a[i][j] = s[i][j] - '0';
				q[a[i][j]].push({ v[a[i][j]], i, j });
			}
		}
	}

	bool flag = true;

	while (flag) 
	{
		for (int x = 1; x <= p; x++)
		{
			while (!q[x].empty())
			{
				auto to = q[x].front(); q[x].pop();
				int c = get<0>(to), i = get<1>(to), j = get<2>(to);

				for (int k = 0; k < 4; k++)
				{
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
					if (a[ni][nj] == -1 || a[ni][nj] != 0) continue;
					a[ni][nj] = x;

					if (c == 1) nq[x].push({ v[x], ni, nj });
					else q[x].push({ c - 1, ni, nj });
				}
			}
		}

		flag = false;

		for (int x = 1; x <= p; x++)
		{
			while (!nq[x].empty())
			{
				flag = true;
				q[x].push(nq[x].front());
				nq[x].pop();
			}
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (a[i][j] == 0 || a[i][j] == -1) continue;
		ans[a[i][j]]++;
	}

	for (int i = 1; i <= p; i++)
		cout << ans[i] << ' ';

}