#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[6] = { 1, -1, 0, 0, 1, 1 };
int dy[6] = { 0, 0, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll N = 4002;
const ll inf = 1e15;

struct Node {
	ll lval, rval, val, all;
};

struct Point {
	ll x, y, cost;
};

Node segTree[N * 4];
Point p[N];
pll tmpX[N], tmpY[N];
ll a[N][N];
vector<pll> yList[N * 2];

Node merge(Node a, Node b)
{
	Node res;
	res.lval = max(a.lval, a.all + b.lval);
	res.rval = max(b.rval, a.rval + b.all);
	res.all = a.all + b.all;
	res.val = max(max(a.val, b.val), a.rval + b.lval);
	return res;
}

Node getVal(int ptr, int s, int e, int l, int r)
{
	if (r < s || e < l)
		return { -inf, -inf, -inf, -inf };

	if (l <= s && e <= r)
		return segTree[ptr];

	return merge(getVal(ptr * 2, s, (s + e) / 2, l, r),
		getVal(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

void update(int ptr, int s, int e, int i, ll val)
{
	if (i < s || e < i)
		return;

	if (s == e)
	{
		segTree[ptr].lval += val; segTree[ptr].rval += val;
		segTree[ptr].val += val; segTree[ptr].all += val;
		return;
	}

	update(ptr * 2, s, (s + e) / 2, i, val);
	update(ptr * 2 + 1, (s + e) / 2 + 1, e, i, val);
	segTree[ptr] = merge(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	
	for (ll i = 1; i <= n; i++)
	{
		cin >> p[i].x >> p[i].y >> p[i].cost;
		tmpX[i] = { p[i].x, i };
		tmpY[i] = { p[i].y, i };
	}

	sort(tmpX + 1, tmpX + n + 1);
	sort(tmpY + 1, tmpY + n + 1);
	ll mx = 1, my = 1;

	for (ll i = 1; i <= n; i++)
	{
		if (i > 1 && tmpX[i - 1].first != tmpX[i].first) mx++;
		p[tmpX[i].second].x = mx;
	}

	for (ll i = 1; i <= n; i++)
	{
		if (i > 1 && tmpY[i - 1].first != tmpY[i].first) my++;
		p[tmpY[i].second].y = my;
	}

	for (ll i = 1; i <= n; i++)
	{
		a[p[i].x][p[i].y] = p[i].cost;
		yList[p[i].y].push_back({ p[i].x, p[i].cost });
	}

	ll ans = 0;

	for (ll k = 1; k <= my; k++)
	{
		memset(segTree, 0, sizeof segTree);
		for (ll i = k; i <= my; i++)
		{
			for (auto& to : yList[i])
			{
				update(1, 1, n, to.first, to.second);
			}
			ans = max(ans, segTree[1].val);
		}
	}

	cout << ans << "\n";
}