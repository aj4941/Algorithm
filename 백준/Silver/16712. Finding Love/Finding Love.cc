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
vector<pii> a;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	a.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	for (int i = 0; i < n - m + 1; i++)
	{
		sort(a.begin(), a.begin() + m);
		vector<pii> b;
		int r; cin >> r;
		for (int j = 0; j < a.size(); j++)
		{
			if (j == r - 1) continue;
			b.push_back(a[j]);
		}

		a.clear();

		for (auto to : b)
			a.push_back(to);

	}

	sort(a.begin(), a.end());

	for (auto to : a)
		cout << to.first << ' ';
}