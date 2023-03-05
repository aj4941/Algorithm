#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int a[202][202];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	priority_queue<ti> pq;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		cin >> a[i][j];
		if (a[i][j] > 0)
			pq.push({ -a[i][j], i, j });
	}

	int s, cx, cy; cin >> s >> cx >> cy;
	queue<ti> q;

	while (s--)
	{
		while (!pq.empty())
		{
			auto to = pq.top(); pq.pop();
			int c = -get<0>(to), x = get<1>(to), y = get<2>(to);
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (a[nx][ny] == 0)
				{
					a[nx][ny] = c;
					q.push({ -c, nx, ny });
				}
			}
		}

		while (!q.empty())
		{
			pq.push(q.front());
			q.pop();
		}
	}

	cout << a[cx - 1][cy - 1];
}