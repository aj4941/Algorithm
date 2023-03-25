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
map<ll, string> cache;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (true)
	{
		ll n; cin >> n;
		if (n == 0) return 0;
		if (n == 1)
		{
			cout << 1 << "\n";
			continue;
		}
		cache[1] = "1";
		queue<ll> q; q.push(1);
		while (!q.empty())
		{
			ll v = q.front(); q.pop();
			ll nv1 = (v * 10) % n;
			ll nv2 = (v * 10 + 1) % n;

			if (!cache.count(nv1))
			{
				cache[nv1] = cache[v] + "0";
				q.push(nv1);
			}
			if (!cache.count(nv2))
			{
				cache[nv2] = cache[v] + "1";
				q.push(nv2);
			}
		}

		cout << cache[0] << "\n";
		cache.clear();
	}
}