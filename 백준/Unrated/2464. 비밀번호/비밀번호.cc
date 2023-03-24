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
const ll MAX = LLONG_MAX - 1;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll A; cin >> A;
	ll cnt = 0;

	for (ll i = 0; i <= 60; i++)
	{
		if (A & (1ll << i))
			cnt++;
	}

	ll lv = -MAX, rv = MAX, cur = 0;

	for (ll i = 61; i >= 0 && cnt > 0; i--)
	{
		if (A & (1ll << i))
		{
			if (i - cnt >= 0)
			{
				ll res = 0;
				for (ll j = i - 1; j >= i - cnt; j--) // cnt
					res += (1ll << j);

				lv = max(lv, res + cur);
			}
		}
		else
		{
			if (cnt - 2 < i)
			{
				ll res = (1ll << i); // 1
				for (ll j = 0; j <= cnt - 2; j++) // cnt - 1
					res += (1ll << j);

				rv = min(rv, res + cur);
			}
		}

		if (A & (1ll << i))
		{
			cnt--;
			cur += (1ll << i);
		}
	}

	if (lv == -MAX) lv = 0;
	if (rv == MAX) rv = 0;

	cout << lv << ' ' << rv;
}