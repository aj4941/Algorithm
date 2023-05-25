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
const int N = 2000002;
int n, m;
pii g[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		int u = a[i], v = a[(i + 1) % n];
		g[u].second = v; g[v].first = u;
	}

	int sz = n;

	for (int i = 0; i < m; i++)
	{
		string s; cin >> s;
		if (s == "BN")
		{
			int u, c; cin >> u >> c;
			int nxt = g[u].second;
			cout << nxt << "\n";
			if (sz == 1)
			{
				g[u].first = c; g[u].second = c;
				g[c].first = u; g[c].second = u;
			}
			else 
			{
				g[u].second = c; g[c].first = u;
				g[nxt].first = c; g[c].second = nxt;
			}
			sz++;

		}
		else if (s == "BP")
		{
			int u, c; cin >> u >> c;
			int prv = g[u].first;
			cout << prv << "\n";
			if (sz == 1)
			{
				g[u].first = c; g[u].second = c;
				g[c].first = u; g[c].second = u;
			}
			else 
			{
				g[prv].second = c; g[c].first = prv;
				g[c].second = u; g[u].first = c;
			}
			sz++;
		}
		else if (s == "CP")
		{
			int u; cin >> u;
			int prv = g[u].first;
			cout << prv << "\n";
			int pprv = g[prv].first;
			g[prv] = pii(0, 0);
			g[u].first = pprv; g[pprv].second = u;
			sz--;
		}
		else
		{
			int u; cin >> u;
			int nxt = g[u].second;
			cout << nxt << "\n";
			int nnxt = g[nxt].second;
			g[nxt] = pii(0, 0);
			g[nnxt].first = u; g[u].second = nnxt;
			sz--;
		}
	}
}