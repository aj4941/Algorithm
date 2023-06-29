#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const int N = 100002;
bitset<N> dp[102];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int t = 0; t < 3; t++)
	{
		int n; cin >> n;
		vector<pii> coin(n);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			dp[i].reset();
			cin >> coin[i].first >> coin[i].second;
			sum += coin[i].first * coin[i].second;
		}

		if (sum % 2)
		{
			cout << 0 << "\n";
			continue;
		}

		sort(coin.begin(), coin.end());
		dp[0][0] = 1;

		for (int i = 0; i < n; i++)
		{
			if (i > 0) dp[i] |= dp[i - 1];
			for (int x = 1; x <= coin[i].second; x++)
			{
				if (i == 0)
					dp[i][coin[i].first * x] = 1;
				else
					dp[i] |= (dp[i - 1] << (coin[i].first * x));
			}
		}

		if (dp[n - 1][sum / 2]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}