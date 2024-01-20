#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[6] = { 1, 1, 0, 0, 1, 1 };
int dy[6] = { -1, 1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 6000002;

struct Node {
	ll l, r, val;
	Node() { l = -1, r = -1, val = 0; }
};
struct query1 {
	int i, j, k;
};

struct query2 {
	int k, idx, i, j;
};

Node segTree[N];
ll lazy[N];
int n, cnt = 2;

void setlazy(int ptr, int s, int e)
{
	ll val = lazy[ptr];
	lazy[ptr] = 0;
	segTree[ptr].val += (e - s + 1) * val;
	if (s != e)
	{
		if (segTree[ptr].l == -1) segTree[ptr].l = cnt++;
		if (segTree[ptr].r == -1) segTree[ptr].r = cnt++;
		lazy[segTree[ptr].l] += val;
		lazy[segTree[ptr].r] += val;
	}
}

void update(int ptr, int s, int e, int l, int r, ll val)
{
	if (lazy[ptr]) setlazy(ptr, s, e);
	if (r < s || e < l)
		return;
	if (l <= s && e <= r)
	{
		segTree[ptr].val += (e - s + 1) * val;
		if (s != e)
		{
			if (segTree[ptr].l == -1) segTree[ptr].l = cnt++;
			if (segTree[ptr].r == -1) segTree[ptr].r = cnt++;
			lazy[segTree[ptr].l] += val;
			lazy[segTree[ptr].r] += val;
		}
		return;
	}
	if (segTree[ptr].l == -1) segTree[ptr].l = cnt++;
	if (segTree[ptr].r == -1) segTree[ptr].r = cnt++;
	update(segTree[ptr].l, s, (s + e) / 2, l, r, val);
	update(segTree[ptr].r, (s + e) / 2 + 1, e, l, r, val);
	segTree[ptr].val = segTree[segTree[ptr].l].val + segTree[segTree[ptr].r].val;
}

ll getVal(int ptr, int s, int e, int l, int r)
{
	if (ptr == -1) return 0;
	if (lazy[ptr]) setlazy(ptr, s, e);
	if (r < s || e < l)
		return 0;
	if (l <= s && e <= r)
		return segTree[ptr].val;

	return getVal(segTree[ptr].l, s, (s + e) / 2, l, r)
		+ getVal(segTree[ptr].r, (s + e) / 2 + 1, e, l, r);
}

bool cmp(query2 a, query2 b)
{
	return a.k < b.k;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	vector<query1> q1;
	vector<query2> q2;
	int idx = 0;
	for (int q = 0; q < n; q++)
	{
		int c, i, j, k;
		cin >> c >> i >> j >> k;
		if (c == 1)
			q1.push_back({ i, j, k });
		else
			q2.push_back({ k - 1, idx++, i, j });
	}
	sort(q2.begin(), q2.end(), cmp);
	int st = 0;
	vector<ll> ans(idx);
	for (int q = 0; q < q2.size(); q++)
	{
		int ed = q2[q].k;
		while (st <= ed)
		{
			int i = q1[st].i, j = q1[st].j, k = q1[st].k;
			st++;
			update(1, 1, 1e9, i, j, k);
		}
		int res = q2[q].idx;
		int i = q2[q].i, j = q2[q].j;
		ans[res] = getVal(1, 1, 1e9, i, j);
	}

	for (int i = 0; i < idx; i++)
		cout << ans[i] << "\n";
}