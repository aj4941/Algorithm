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
vector<ti> v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int idx, l, r; cin >> idx >> l >> r;
		v.push_back({ l, 0, idx });
		v.push_back({ r - 1, 1, idx });
	}

	sort(v.begin(), v.end());
	int ans = 0, cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		auto to = v[i];
		int x = get<0>(to), c = get<1>(to);
		if (c == 0) cnt++;
		else cnt--;
		ans = max(ans, cnt);
	}

	cout << ans;
}