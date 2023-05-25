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
vector<pii> a;
vector<int> xpos, ypos;
bool hasAns = false;
int n;

void dfs(int idx, int cnt)
{
	if (idx == n)
	{
		if (cnt <= 3)
			hasAns = true;
		return;
	}

	bool flag = false;
	int x = a[idx].first, y = a[idx].second;

	for (auto to : xpos)
	{
		if (x == to)
			flag = true;
	}

	for (auto to : ypos)
	{
		if (y == to)
			flag = true;
	}

	if (flag) dfs(idx + 1, cnt);
	else if (cnt < 3)
	{
		xpos.push_back(x);
		dfs(idx + 1, cnt + 1);
		xpos.pop_back();

		ypos.push_back(y);
		dfs(idx + 1, cnt + 1);
		ypos.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int u, v; cin >> u >> v;
		a.push_back({ u, v });
	}

	dfs(0, 0);

	if (hasAns) cout << 1;
	else cout << 0;
}