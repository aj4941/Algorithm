#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int gcd(int a, int b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	ll ans = 0;

	for (ll i = 0; i < n; i++)
	{
		ll l = 0, r = n - 1;
		bool hasAns = false;
		while (l < r)
		{
			ll sum = a[l] + a[r];
			if (sum == a[i])
			{
				if (l == i) l++;
				else if (r == i) r--;
				else
				{
					hasAns = true;
					break;
				}
				continue;
			}
			else if (sum < a[i]) l++;
			else r--;
		}

		if (hasAns) ans++;
	}

	cout << ans;
}