#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n, m;
int dp[52][502];
vector<vector<int>> company;

int solve(int i, int M) // i : 기업, M : 남은 금액
{
	int& ret = dp[i][M];
	if (ret != -1) return ret;
	if (i == m)
	{
		if (M == 0) return ret = 0;
		return ret = -1e9;
	}
	ret = solve(i + 1, M);
	for (int x = 0; x < n && M - (x + 1) >= 0; x++)
		ret = max(ret, solve(i + 1, M - (x + 1)) + company[x][i]);

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		company.push_back({});
		for (int j = 0; j < m; j++)
		{
			int y; cin >> y;
			company.back().push_back(y);
		}
	}

	cout << solve(0, n) << "\n";

	int i = 0, M = n;
	vector<int> ans(m);
	while (i < m)
	{
		if (dp[i + 1][M] == dp[i][M])
		{
			i++;
			continue;
		}

		for (int x = 0; x < n && M - (x + 1) >= 0; x++)
		{
			if (dp[i + 1][M - (x + 1)] + company[x][i] == dp[i][M])
			{
				ans[i] += x + 1;
				M -= (x + 1);
				break;
			}
		}
		i++;
	}

	for (auto to : ans)
		cout << to << ' ';

}