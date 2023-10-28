#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long long ll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
    
	sort(a.begin(), a.end());

	for (ll i = 0; i < n - 1; i++)
	{
		if (a[i] + 1 == a[i + 1])
		{
			ll idx = lower_bound(a.begin(), a.end(), a[i] + 2) - a.begin();
			if (idx != a.size())
				swap(a[i + 1], a[idx]);
			else
			{
				ll val = a[i];
				while (i > 0 && a[i - 1] == val) i--;
				reverse(a.begin() + i, a.end());
				break;
			}
		}
	}

	for (auto to : a)
		cout << to << ' ';
}