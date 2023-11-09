#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const ll N = 2000;
ll a[N][N];

ll solve(ll x1, ll y1, ll x2, ll y2)
{
	return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m; cin >> n >> m;
	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
		cin >> a[i][j];

	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
		a[i][j] += a[i][j - 1];

	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
		a[i][j] += a[i - 1][j];

	for (ll i = 0; i < m; i++)
	{
		ll x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2;
		cout << solve(x1, y1, x2, y2) << "\n";
	}
}