#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n;

void dfs(int x, int y)
{
	int len = 2 * x + y;
	if (len < n)
	{
		dfs(len, y + 1);
		return;
	}
	if (x < n && n <= x + y)
	{
		if (n == x + 1) cout << 'm';
		else cout << 'o';
		return;
	}
	else
	{
		n -= (x + y);
		dfs(0, 3);
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	dfs(0, 3);
}