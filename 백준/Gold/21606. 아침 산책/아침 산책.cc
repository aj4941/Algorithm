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
const int N = 200005;
vector<int> g[N];
int n;
string s;
ll cnt[N], sz[N], p[N];

int find(int x)
{
	if (p[x] == x)
		return x;
	else
		return p[x] = find(p[x]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;

	for (int i = 1; i <= n; i++) p[i] = i;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	
	for (int v = 1; v <= n; v++)
	{
		if (s[v - 1] == '1') continue;
		for (int nv : g[v])
		{
			if (s[nv - 1] == '1')
				cnt[v]++;
		}
	}

	for (int v = 1; v <= n; v++)
	{
		if (s[v - 1] == '1') continue;
		for (int nv : g[v])
		{
			if (s[nv - 1] == '0')
			{
				int a = find(v), b = find(nv);
				p[a] = b; cnt[b] += cnt[a]; cnt[a] = 0;
			}
		}
	}

	ll ans = 0;

	for (int v = 1; v <= n; v++)
	{
		if (s[v - 1] == '0') continue;
		for (int nv : g[v])
		{
			if (s[nv - 1] == '0')
			{
				int a = find(nv);
				ans += cnt[a] - 1;
			}
			else
				ans++;
		}
 	}

	cout << ans;
}