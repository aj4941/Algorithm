#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000007

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<ll> a(n);
	vector<ll> p, m;
	ll zero = 0, one = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > 1) p.push_back(a[i]);
		else if (a[i] == 1) one++;
		else if (a[i] == 0) zero++;
		else m.push_back(-a[i]);
	}
	ll ans = one;
	sort(p.rbegin(), p.rend()); sort(m.rbegin(), m.rend());
	for (ll i = 0; i < max(0, (int)p.size() - 1); i += 2)
		ans += p[i] * p[i + 1];
	for (ll i = 0; i < max(0, (int)m.size() - 1); i += 2)
		ans += m[i] * m[i + 1];
	if (p.size() % 2) ans += p.back();
	if (m.size() % 2 && zero == 0) ans -= m.back();
	cout << ans;
}