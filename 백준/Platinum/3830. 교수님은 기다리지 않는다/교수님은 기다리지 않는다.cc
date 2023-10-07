#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000007
const int MAX = 100001;
int n, m, root[MAX];
ll dist[MAX];

int update(int x)
{
	if (root[x] == x) return x;
	int r = update(root[x]);
	dist[x] += dist[root[x]];
	return root[x] = r;
}

void merge(int a, int b, int diff)
{
	int aRoot = root[a];
	int bRoot = root[b];
	if (aRoot == bRoot) return;
	int newD = dist[a] + diff;
	int originD = dist[b];
	root[bRoot] = aRoot;
	dist[bRoot] = newD - originD;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++)
		{
			root[i] = i;
			dist[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			char ch;
			int a, b, w;
			cin >> ch >> a >> b;
			update(a); update(b); 
			if (ch == '!')
			{
				cin >> w;
				merge(a, b, w);
			}
			else
			{
				if (root[a] == root[b]) cout << dist[b] - dist[a] << "\n";
				else cout << "UNKNOWN" << "\n";
			}
		}
	}
}