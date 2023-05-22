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
	int n; cin >> n;
	vector<pii> v;

	ll total = 0;

	for (int i = 0; i < n; i++)
	{
		int x, cnt; cin >> x >> cnt;
		v.push_back({ x, cnt });
		total += cnt;
	}

	total = (total + 1) / 2;
	sort(v.begin(), v.end());

	for (auto to : v)
	{
		if (total - to.second > 0)
			total -= to.second;
		else
		{
			cout << to.first;
			return 0;
		}
	}
}