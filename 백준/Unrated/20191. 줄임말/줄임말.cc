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
string a, b;
vector<int> v[30];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b;
	for (int i = 0; i < b.size(); i++)
	{
		int val = b[i] - 'a';
		v[val].push_back(i);
	}

	int i = 0, idx = 0;
	int ans = 1;

	while (i < a.size())
	{
		int val = a[i] - 'a';
		if (v[val].size() == 0)
		{
			cout << -1;
			return 0;
		}

		int nidx = lower_bound(v[val].begin(), v[val].end(), idx) - v[val].begin();
		if (nidx == v[val].size())
		{
			ans++;
			idx = 0;
		}
		else
		{
			idx = v[val][nidx] + 1;
			i++;
		}
	}

	cout << ans;
}