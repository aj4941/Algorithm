#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m, q; cin >> n >> m >> q;
	for (ll i = 0; i < q; i++)
	{
		ll x, y; cin >> x >> y;
	}

	ll cnt = 1;
	string ans = "";
	char c = 'a';
	while (ans.size() < m)
	{
		ans += c;
		if (ans.size() < m)
		{
			ans += c++;
			cnt++;
			if (cnt > n)
			{
				cnt = 1;
				c = 'a';
			}
		}
	}

	cout << ans;

}