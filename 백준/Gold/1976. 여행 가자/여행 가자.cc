#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
#define INF 987654321
const ll N = 202;
ll a[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m; cin >> n >> m;
	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
		cin >> a[i][j];

	for (ll i = 1; i <= n; i++) a[i][i] = 1;

	for (ll k = 1; k <= n; k++)
	{
		for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++)
		{
			if (a[i][k] && a[k][j])
				a[i][j] = 1;
		}
	}

	vector<ll> v(m);
	for (ll i = 0; i < m; i++) cin >> v[i];

	bool hasAns = true;

	for (ll i = 1; i < m; i++)
	{
		ll x = v[i - 1], y = v[i];
		if (a[x][y] == 0) hasAns = false;
	}

	if (hasAns)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}