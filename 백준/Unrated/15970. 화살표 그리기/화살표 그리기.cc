#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 5002;
vector<int> color[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < N; i++)
	{
		color[i].push_back(-1e9);
		color[i].push_back(1e9);
	}

	for (int i = 0; i < n; i++)
	{
		int x, c; cin >> x >> c;
		color[c].push_back(x);
	}

	for (int i = 0; i < N; i++)
		sort(color[i].begin(), color[i].end());

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		if (color[i].size() == 2) continue;
		for (int j = 1; j < (int)color[i].size() - 1; j++)
		{
			int lv = abs(color[i][j - 1] - color[i][j]);
			int rv = abs(color[i][j + 1] - color[i][j]);
			ans += min(lv, rv);
		}
	}

	cout << ans;
}