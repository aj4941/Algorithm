#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[6] = { 1, 1, 0, 0, 1, 1 };
int dy[6] = { -1, 1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	vector<bool> cache(n, true);

	for (int i = 0; i < n; i++)
	{
		if (cache[i] == false) continue;
 		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (cache[j] == false) continue;
			if (v[i].size() > v[j].size()) continue;
			if (v[i] == v[j].substr(0, v[i].size()))
				cache[i] = false;
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (cache[i] == true)
			ans++;
	}

	cout << ans;
}