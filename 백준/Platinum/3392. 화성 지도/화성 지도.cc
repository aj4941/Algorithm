#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int gcd(int a, int b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1e18
const int MAXN = 30002;
int n, ans;
int cnt[MAXN << 2], segTree[MAXN << 2];
vector<pair<pii, pii>> edge;

void update(int ptr, int s, int e, int l, int r, ll val)
{
	if (r < s || e < l) return;
	if (l <= s && e <= r)
		segTree[ptr] += val;
	else
	{
		update(ptr * 2, s, (s + e) / 2, l, r, val);
		update(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
	}
	if (segTree[ptr]) cnt[ptr] = e - s + 1;
	else if (s == e) cnt[ptr] = 0;
	else cnt[ptr] = cnt[ptr * 2] + cnt[ptr * 2 + 1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		edge.push_back({ { a, 1 }, { b, d } });
		edge.push_back({ { c, -1 }, { b, d } });
	}
	sort(edge.begin(), edge.end());
	ll ans = 0;
	int prv = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		int x = edge[i].first.first;
		int val = edge[i].first.second;
		int y1 = edge[i].second.first;
		int y2 = edge[i].second.second;
		if (i) ans += (x - prv) * cnt[1];
		prv = x;
		update(1, 0, MAXN, y1, y2 - 1, val);
	}
	cout << ans;
}