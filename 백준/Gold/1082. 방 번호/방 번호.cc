#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool cmp(pll& a, pll& b)
{
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<ll> p(n);
	vector<pll> v;
	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;
		v.push_back({ x, i });
		p[i] = x;
	}
	sort(v.begin(), v.end(), cmp);
	ll m; cin >> m;
	string ans = "";

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	if (v[0].second == 0)
	{
		m -= v[1].first;
		if (m < 0)
		{
			cout << 0;
			return 0;
		}
		ans += v[1].second + '0';
		ll inc = m / v[0].first;
		for (ll i = 0; i < inc; i++)
			ans += v[0].second + '0';
		m %= v[0].first;
	}
	else
	{
		ll inc = m / v[0].first;
		for (ll i = 0; i < inc; i++)
			ans += v[0].second + '0';
		m %= v[0].first;
	}

	for (ll i = 0; i < ans.size(); i++)
	{
		ll idx = ans[i] - '0'; // p[idx] : 현재 사용된 비용
		for (ll j = n - 1; j >= 0; j--)
		{
			if (m - (p[j] - p[idx]) >= 0)
			{
				ans[i] = j + '0';
				m -= (p[j] - p[idx]);
				break;
			}
		}
	}

	cout << ans;
}