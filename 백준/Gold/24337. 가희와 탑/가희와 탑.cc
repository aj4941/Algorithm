#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll n, a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> a >> b;
	if (a + b - 1 > n)
	{
		cout << -1;
		return 0;
	}
	vector<ll> v1, v2;
	for (ll i = 1; i <= a - 1; i++) v1.push_back(i);
	for (ll i = b - 1; i >= 1; i--) v2.push_back(i);
	ll rm = n - (a + b - 1);
	deque<ll> ans;
	for (auto to : v1) ans.push_back(to);
	ans.push_back(max(a, b));
	for (auto to : v2) ans.push_back(to);
	ll val = ans.front();
	if (val == 1)
	{
		for (ll i = 0; i < rm; i++)
			ans.push_front(1);
	}
	else
	{
		ll fv = ans.front(); ans.pop_front();
		for (ll i = 0; i < rm; i++)
			ans.push_front(1);
		ans.push_front(fv);
	}
	for (auto to : ans)
		cout << to << ' ';
}