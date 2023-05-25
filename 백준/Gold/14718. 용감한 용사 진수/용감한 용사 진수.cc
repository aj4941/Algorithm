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
vector<ti> v;
int n, K;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> K;
	for (int i = 0; i < n; i++)
	{
		ll x, y, z; cin >> x >> y >> z;
		v.push_back({ x, y, z });
	}

	ll ans = 1e9;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				ll res = get<0>(v[i]) + get<1>(v[j]) + get<2>(v[k]);
				int cnt = 0;

				for (int l = 0; l < n; l++)
				{
					if (get<0>(v[l]) <= get<0>(v[i]) &&
						get<1>(v[l]) <= get<1>(v[j]) &&
						get<2>(v[l]) <= get<2>(v[k])) cnt++;
				}

				// cout << cnt << endl;

				if (cnt >= K)
				{
					// cout << i << ' ' << j << ' ' << k << endl;
					ans = min(ans, res);
				}
			}
		}
	}

	cout << ans;
}