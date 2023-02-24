#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 1002;
int dist[N][N], a[N][N];
int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dist, -1, sizeof dist);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> a[i][j];
	
	if (a[0][0] == -1)
	{
		cout << -1;
		return 0;
	}

	dist[0][0] = a[0][0];
	priority_queue<pair<int, pii>> pq; 
	pq.push({ -dist[0][0], { 0, 0 } });

	while (!pq.empty())
	{
		int d = -pq.top().first;
		int x = pq.top().second.first, y = pq.top().second.second; pq.pop();
		if (dist[x][y] != d) continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (a[nx][ny] == -1) continue;
			if (dist[nx][ny] == -1 || d + a[nx][ny] < dist[nx][ny])
			{
				dist[nx][ny] = d + a[nx][ny];
				pq.push({ -dist[nx][ny], { nx, ny } });
			}
		}
	}

	cout << dist[n - 1][m - 1];
}