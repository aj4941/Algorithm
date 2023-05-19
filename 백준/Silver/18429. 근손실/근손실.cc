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
int n, k;
vector<int> a, p;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k; a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) p.push_back(i);

	ll ans = 0;

	do {
		bool hasAns = true;
		ll res = 500;
		for (int i = 0; i < n; i++)
		{
			res += a[p[i]] - k;
			if (res < 500) hasAns = false;
		}
		if (hasAns) ans++;
	} while (next_permutation(p.begin(), p.end()));

	cout << ans;
}