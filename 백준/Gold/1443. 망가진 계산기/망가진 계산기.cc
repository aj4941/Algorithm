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
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll d, p;
ll ans = -1;
map<pair<ll, ll>, int> mp;

ll calc(ll num)
{
	ll cnt = 0;
	while (num > 0)
	{
		num /= 10;
		cnt++;
	}

	return cnt;
}

void dfs(ll num, ll cnt)
{
	if (cnt == p)
	{
		ans = max(ans, num);
		return;
	}

	for (ll i = 2; i <= 9; i++)
	{
		if (d < calc(num * i)) break;
		if (mp.count({ num * i, cnt + 1 })) continue;
		mp[{ num * i, cnt + 1 }] = 1;
		dfs(num * i, cnt + 1);
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> d >> p;
	dfs(1, 0);

	cout << ans;
}
