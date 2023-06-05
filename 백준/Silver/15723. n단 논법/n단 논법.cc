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
const int N = 100;
vector<int> g[N];
bool cache[N];

void dfs(int v)
{
	cache[v] = true;
	for (int nv : g[v])
	{
		if (cache[nv]) continue;
		dfs(nv);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s; getline(cin, s);
		int u = s.front() - 'a', v = s.back() - 'a';
		g[u].push_back(v);
	}

	int m; cin >> m;
	cin.ignore();
	for (int i = 0; i < m; i++)
	{
		string s; getline(cin, s);
		int u = s.front() - 'a', v = s.back() - 'a';
		memset(cache, false, sizeof cache);
		dfs(u);

		if (cache[v]) cout << "T";
		else cout << "F";
		cout << "\n";
	}
}