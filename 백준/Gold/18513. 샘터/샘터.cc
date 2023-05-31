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
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 200002;
int n, k;
int a[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	priority_queue<pii> pq;
	map<int, bool> mp;

	for (int i = 0; i < n; i++)
	{
		int x; cin >> x; mp[x] = true;
		pq.push({ -1, x - 1 });
		pq.push({ -1, x + 1 });
	}

	ll ans = 0, cnt = 0;

	while (!pq.empty() && cnt < k)
	{
		auto to = pq.top(); pq.pop();
		int d = -to.first, v = to.second;
		if (mp.count(v)) continue;
		
		ans += d; cnt++;
		mp[v] = true;

		if (!mp.count(v - 1)) pq.push({ -(d + 1), v - 1 });
		if (!mp.count(v + 1)) pq.push({ -(d + 1), v + 1 });
	}

	cout << ans;
}