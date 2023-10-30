#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<ll> a(n), ans(n, -1);
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++)
	{
		ll cnt = 0;
		for (ll j = 0; j < n; j++)
		{
			if (ans[j] != -1) continue;
			if (cnt == a[i])
			{
				ans[j] = i + 1;
				break;
			}
			cnt++;
		}
	}
	for (auto to : ans)
		cout << to << ' ';
}