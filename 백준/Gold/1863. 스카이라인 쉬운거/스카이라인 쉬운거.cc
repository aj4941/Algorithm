#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<pll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	ll ans = 0;
	vector<ll> stk;

	for (ll i = 0; i < n; i++)
	{
		if (a[i].second == 0)
		{
			ans += stk.size();
			stk.clear();
			continue;
		}
		while (stk.size() && stk.back() > a[i].second)
		{
			ans++;
			stk.pop_back();
		}

		if (stk.size() && stk.back() != a[i].second)
			stk.push_back(a[i].second);
		else if (stk.empty())
			stk.push_back(a[i].second);
	}

	ans += stk.size();
	cout << ans;
}