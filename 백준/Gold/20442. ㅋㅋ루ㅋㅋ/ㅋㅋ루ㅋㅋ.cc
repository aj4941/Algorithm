#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll cnt[3000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s; cin >> s;
	deque<ll> dq;
	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == 'K')
			dq.push_back(i + 1);

		if (s[i] == 'R')
			cnt[i + 1] = cnt[i] + 1;
		else
			cnt[i + 1] = cnt[i];
	}

	ll ans = cnt[s.size()];
	ll p = 0;
	while (dq.size() >= 2)
	{
		ll l = dq.front(), r = dq.back();
		dq.pop_front(); dq.pop_back(); p += 2;
		ll mid = cnt[r - 1] - cnt[(l + 1) - 1];
		if (mid == 0) break;
		ans = max(ans, mid + p);
	}
	cout << ans;
}