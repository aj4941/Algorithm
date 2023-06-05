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
int n, m;
vector<int> stk, a;
vector<int> prv;

void dfs(int idx)
{
	if (stk.size() == m)
	{
		if (prv == stk)
			return;

		for (auto to : stk)
			cout << to << ' ';
		cout << "\n";

		prv = stk;
		return;
	}

	if (idx == n)
		return;

	for (int i = idx; i < n; i++)
	{
		if (i > idx && a[i] == a[i - 1]) continue;
		stk.push_back(a[i]);
		dfs(i + 1);
		stk.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	dfs(0);
}