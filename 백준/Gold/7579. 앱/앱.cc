#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[6] = { 1, -1, 0, 0, 1, 1 };
int dy[6] = { 0, 0, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll dp[10002], c[102], m[102];
const ll MAX = 10000;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, M; cin >> n >> M;
	for (ll i = 1; i <= n; i++) cin >> m[i];
	for (ll i = 1; i <= n; i++) cin >> c[i];
	for (ll i = 1; i <= n; i++) for (ll j = MAX; j >= c[i]; j--)
	{
		dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
	}

	ll ans = 1e15;

	for (ll j = 0; j <= MAX; j++)
	{
		if (dp[j] >= M)
			ans = min(ans, j);
	}

	cout << ans;
}