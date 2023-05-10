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
map<pii, int> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int A, B; cin >> A >> B;

	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		mp[{ x, y }] = 1;
	}

	ll ans = 0;

	for (auto to : mp)
	{
		int x = to.first.first, y = to.first.second;
		if (mp.count({ x + A, y }) && mp.count({ x, y + B }) && mp.count({ x + A, y + B }))
			ans++;
	}

	cout << ans;
}