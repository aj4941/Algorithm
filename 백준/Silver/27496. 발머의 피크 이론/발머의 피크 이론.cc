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
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	ll sum = 0, ans = 0;
    
	for (int i = 0; i < m; i++)
	{
		sum += a[i];
		if (129 <= sum && sum <= 138)
			ans++;
	}

	for (int i = m; i < n; i++)
	{
		sum -= a[i - m]; sum += a[i];
		if (129 <= sum && sum <= 138)
			ans++;
	}

	cout << ans;
}