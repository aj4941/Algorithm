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
int n, m;
string s[N];
ll ans = -1;

void calc(ll val)
{
	ll l = 0, r = 1e9; // [l, r)
	while (l + 1 < r)
	{
		ll mid = (l + r) / 2;
		if (mid * mid > val) r = mid;
		else l = mid;
	}

	if (l * l == val)
		ans = max(ans, val);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int xd = -n; xd <= n; xd++) for (int yd = -m; yd <= m; yd++)
	{
		if (xd == 0 && yd == 0) continue;
		for (int x = 0; x < n; x++) for (int y = 0; y < m; y++)
		{
			int cx = x, cy = y;
			ll val = s[cx][cy] - '0';
			while (true)
			{
				calc(val);
				cx += xd, cy += yd;
				if (cx < 0 || cy < 0 || cx >= n || cy >= m) break;
				val = val * 10 + s[cx][cy] - '0'; 
			}
		}
	}

	cout << ans;
}