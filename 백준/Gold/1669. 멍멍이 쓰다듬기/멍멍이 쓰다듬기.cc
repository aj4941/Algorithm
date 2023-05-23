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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll a, b; cin >> a >> b;
	ll d = b - a;
	if (d <= 2)
	{
		cout << d;
		return 0;
	}

	ll cur_d = 2, c = 2, k = 2, ans = 2;

	while (cur_d < d)
	{
		cur_d += c; ans++;
		k--;

		if (k == 0)
		{
			c++;
			k = 2;
		}
	}

	cout << ans;
}