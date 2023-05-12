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
const int N = 20;
string s[N];
int n, m;
map<ll, ll> cache;
ll ans = -1;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (ll num = 0; num <= 1e5; num++) 
		cache[num * num] = 1;

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> s[i];

	for (int x = 0; x < n; x++) for (int y = 0; y < m; y++)
	{
		ll val = s[x][y] - '0';
		if (cache.count(val)) ans = max(ans, val);
		if (val == 0) continue;
		for (int xk = -n; xk < n; xk++) for (int yk = -m; yk < m; yk++)
		{
			string tmp = string("") + s[x][y];
			if (xk == 0 && yk == 0) continue;
			int nx = x + xk, ny = y + yk;
			while (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				tmp += s[nx][ny];
				ll val = stoll(tmp);
				if (cache.count(val)) ans = max(ans, val);
				nx += xk, ny += yk;
			}
		}
	}

	cout << ans;
}