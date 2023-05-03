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
	vector<pii> v;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r; cin >> l >> r;
		v.push_back({ l, 0 });
		v.push_back({ r - 1, 1 });
	}

	sort(v.begin(), v.end());
	ll ans = 0, cnt = 0;

	for (auto to : v)
	{
		int c = to.second;
		if (c == 0) cnt++;
		else cnt--;

		ans = max(ans, cnt);
	}

	cout << ans;
}