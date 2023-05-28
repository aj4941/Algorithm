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
const int N = 200002;
pii segTree[N * 4]; // min, max
int n, m;
int a[N], pos[N];

void update(int ptr, int s, int e, int i, int val)
{
	if (i < s || e < i)
		return;

	if (s == e)
	{
		segTree[ptr] = pii(val, val);
		return;
	}
	
	update(ptr * 2, s, (s + e) / 2, i, val);
	update(ptr * 2 + 1, (s + e) / 2 + 1, e, i, val);
	pii r1 = segTree[ptr * 2], r2 = segTree[ptr * 2 + 1];
	segTree[ptr].first = min(r1.first, r2.first);
	segTree[ptr].second = max(r1.second, r2.second);
}

pii getVal(int ptr, int s, int e, int l, int r)
{
	if (r < s || e < l)
		return pii(1e9, -1e9);
	if (l <= s && e <= r)
		return segTree[ptr];

	pii r1 = getVal(ptr * 2, s, (s + e) / 2, l, r);
	pii r2 = getVal(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r);

	return { min(r1.first, r2.first), max(r1.second, r2.second) };
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x; pos[i] = x;
		update(1, 1, n, x, i);
	}

	for (int i = 0; i < m; i++)
	{
		int c, x, y; cin >> c >> x >> y;
		if (c == 1)
		{
			int vx = pos[x], vy = pos[y];
			pos[y] = vx, pos[x] = vy;
			update(1, 1, n, vx, y);
			update(1, 1, n, vy, x);
		}
		else
		{
			int len = y - x + 1;
			pii res = getVal(1, 1, n, x, y);
			int mn = res.first, mx = res.second;
			if (mn + len - 1 == mx)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
}