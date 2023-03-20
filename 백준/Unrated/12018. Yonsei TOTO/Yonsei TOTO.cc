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
vector<int> res;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int len, k; cin >> len >> k;
		vector<int> v(len);
		for (int j = 0; j < len; j++)
			cin >> v[j];

		sort(v.rbegin(), v.rend());
		if (len < k) res.push_back(1);
		else res.push_back(v[k - 1]);
	}

	sort(res.begin(), res.end());

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (m - res[i] >= 0)
		{
			ans++;
			m -= res[i];
		}
		else
			break;
	}

	cout << ans;
}