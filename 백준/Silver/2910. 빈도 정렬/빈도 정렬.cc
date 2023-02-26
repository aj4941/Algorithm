#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, c; cin >> n >> c;
	map<int, int> cnt, st;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x; cnt[x]++;
		if (!st.count(x)) st[x] = i;
	}

	vector<pair<pii, int>> v;

	for (auto to : cnt)
	{
		int x = to.first;
		v.push_back({ { -cnt[x], st[x] }, x });
	}

	sort(v.begin(), v.end());

	for (auto to : v) {
		int x = to.second;
		int sz = -to.first.first;
		for (int i = 0; i < sz; i++)
			cout << x << ' ';
	}
}