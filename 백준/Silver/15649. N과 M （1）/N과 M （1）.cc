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
vector<int> a, stk;
int cache[10];

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << stk[i] << ' ';
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (cache[a[i]] == 0) 
		{
			cache[a[i]] = 1;
			stk.push_back(a[i]);
			dfs(cnt + 1);
			stk.pop_back();
			cache[a[i]] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		a.push_back(i + 1);

	dfs(0);
}