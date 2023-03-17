#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100005;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	ll sum = 0, mx = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i]; mx = max(mx, a[i]);
	}

	ll sum1 = a[0] + a[1], sum2 = a[0] + a[1];
	ll ans = 2 * sum - sum1 - sum2;

	for (int i = 2; i < n; i++)
	{
		sum1 -= a[i - 1], sum1 += a[i];
		sum2 += a[i];
		ans = max(ans, 2 * sum - sum1 - sum2);
	}

	reverse(a.begin(), a.end());
	sum1 = a[0] + a[1], sum2 = a[0] + a[1];
	ans = max(ans, 2 * sum - sum1 - sum2);

	for (int i = 2; i < n; i++)
	{
		sum1 -= a[i - 1], sum1 += a[i];
		sum2 += a[i];
		ans = max(ans, 2 * sum - sum1 - sum2);
	}

	ans = max(ans, sum - a.front() - a.back() + mx);
	cout << ans;
}