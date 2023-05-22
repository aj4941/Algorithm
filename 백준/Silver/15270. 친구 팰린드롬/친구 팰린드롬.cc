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
vector<pii> res;
bool cache[50];
int ans = 0;

void dfs(int idx, int cnt)
{
	if (idx == res.size())
	{
		ans = max(ans, cnt);
		return;
	}
	int a = res[idx].first, b = res[idx].second;
	if (!cache[a] && !cache[b])
	{
		cache[a] = cache[b] = true;
		dfs(idx + 1, cnt + 2);
		cache[a] = cache[b] = false;
	}
	dfs(idx + 1, cnt);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		res.push_back({ u, v });
	}

	dfs(0, 0);
	if (ans < n) ans++;
	cout << ans;
}