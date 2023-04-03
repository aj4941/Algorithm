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
	int m, n, L; cin >> m >> n >> L;
	vector<int> a(m), cache(m);
	for (int i = 0; i < m; i++) cin >> a[i];

	sort(a.begin(), a.end());
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		if (L - y < 0) continue;
		int lv = lower_bound(a.begin(), a.end(), x - (L - y)) - a.begin();
		int rv = upper_bound(a.begin(), a.end(), x + (L - y)) - a.begin();
		if (rv - lv > 0) ans++;
	}

	cout << ans;
}