#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
#define MOD 1000000007
const int N = 52;
int p[N * N];
int s[N * N];
string st[N];
bool cache[N][N];
int dist[N][N];
vector<pair<int, pii>> edge;
// 시작점에서 로봇을 원하는만큼 복제하여 퍼지는 방식

















int find(int x)
{
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n * n; i++)
	{
		p[i] = i;
		s[i] = 1;
	}
	for (int i = 0; i < n; i++) cin >> st[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		if (st[i][j] == 'S' || st[i][j] == 'K')
		{
			queue<pii> q; q.push({ i, j });
			int si = i, sj = j;
			memset(cache, false, sizeof cache);
			memset(dist, -1, sizeof dist);
			cache[i][j] = true; dist[i][j] = 0;
			while (!q.empty())
			{
				int x = q.front().first, y = q.front().second; q.pop();
				for (int c = 0; c < 4; c++)
				{
					int nx = x + dx[c], ny = y + dy[c];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (cache[nx][ny] || dist[nx][ny] != -1) continue;
					if (st[nx][ny] == '1') continue;
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny }); cache[nx][ny] = true;
					if (st[nx][ny] == 'S' || st[nx][ny] == 'K')
					{
						int u = si * n + (sj + 1), v = nx * n + (ny + 1);
						edge.push_back({ dist[nx][ny], { u, v } });
					}
				}
			}
		}
	}
	int ans = 0, mx_size = 1;
	sort(edge.begin(), edge.end());
	for (auto to : edge)
	{
		int x = to.second.first, y = to.second.second;
		int w = to.first;
		if (find(x) != find(y))
		{
			x = find(x), y = find(y);
			p[x] = y; s[y] += s[x]; s[x] = 0;
			mx_size = max(mx_size, s[y]);
			ans += w;
		}
	}
	if (mx_size != m + 1)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
}