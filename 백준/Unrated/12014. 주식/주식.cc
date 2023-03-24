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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int n, k; cin >> n >> k;
		vector<int> a(n), v;
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < n; i++)
		{
			int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			if (idx == v.size()) v.push_back(a[i]);
			else v[idx] = a[i];
		}

		cout << "Case #" << tc << "\n";

		if (v.size() >= k)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}