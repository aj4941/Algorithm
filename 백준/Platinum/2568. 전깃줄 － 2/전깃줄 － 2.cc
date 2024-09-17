#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 500002;
bool cache[N];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<pll> a;
	vector<ll> v, p(n);
	for (ll i = 0; i < n; i++)
	{
		ll x, y; cin >> x >> y;
		a.push_back({ x, y });
	}
	sort(a.begin(), a.end());
	for (ll i = 0; i < n; i++)
	{
		if (i == 0)
		{
			v.push_back(a[i].second);
			p[i] = v.size() - 1;
		}
		else
		{
			ll idx = lower_bound(v.begin(), v.end(), a[i].second) - v.begin();
			if (idx == v.size())
			{
				v.push_back(a[i].second);
				p[i] = v.size() - 1;
			}
			else
			{
				v[idx] = a[i].second;
				p[i] = idx;
			}
		}
	}
	ll idx = v.size() - 1;
	for (ll i = n - 1; i >= 0; i--)
	{
		if (p[i] == idx)
		{
			cache[a[i].first] = true;
			idx--;
		}
	}
	vector<ll> ans;
	for (auto to : a)
	{
		if (cache[to.first] == false)
			ans.push_back(to.first);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto to : ans)
		cout << to << "\n";
}