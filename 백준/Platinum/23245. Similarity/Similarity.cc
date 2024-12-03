#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const ll N = 1000002;
ll ans[N * 4], cnt[N * 4], tmp[N];

void update(ll* segTree, int ptr, int s, int e, int i, ll val)
{
	if (i < s || e < i)
		return;

	if (s == e)
	{
		segTree[ptr] += val;
		return;
	}

	update(segTree, ptr * 2, s, (s + e) / 2, i, val);
	update(segTree, ptr * 2 + 1, (s + e) / 2 + 1, e, i, val);
	segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}

ll getVal(ll* segTree, int ptr, int s, int e, int l, int r)
{
	if (r < s || e < l)
		return 0;

	if (l <= s && e <= r)
		return segTree[ptr];

	return getVal(segTree, ptr * 2, s, (s + e) / 2, l, r)
		+ getVal(segTree, ptr * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector<pll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i].first;
	for (ll i = 0; i < n; i++) cin >> a[i].second;

	sort(a.begin(), a.end());

	ll i = 0, j = 0;
	ll res = 0;

	while (i < n)
	{
		while (j < n && a[i].first == a[j].first)
		{
			res += getVal(ans, 1, 0, N, 0, a[j].second - 1);
			tmp[j] = getVal(cnt, 1, 0, N, 0, a[j].second - 1);
			j++;
		}

		while (i < j)
		{
			update(cnt, 1, 0, N, a[i].second, 1);
			update(ans, 1, 0, N, a[i].second, tmp[i]);
			i++;
		}
	}

	cout << res;
}