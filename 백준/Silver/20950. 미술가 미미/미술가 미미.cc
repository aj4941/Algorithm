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
vector<ti> v;
vector<int> res;
int cr, cg, cb;
int n;
int ans = 1e9;

void dfs(int idx)
{
	if (res.size() > 1 && res.size() <= 7)
	{
		int sr = 0, sg = 0, sb = 0;
		for (auto to : res)
		{
			int r = get<0>(v[to]), g = get<1>(v[to]), b = get<2>(v[to]);
			sr += r; sg += g; sb += b;
		}
		sr /= res.size(); sg /= res.size(); sb /= res.size();
		int value = abs(cr - sr) + abs(cg - sg) + abs(cb - sb);
		ans = min(ans, value);
	}

	if (res.size() > 7)
		return;

	if (idx == n)
		return;

	res.push_back(idx);
	dfs(idx + 1);
	res.pop_back();

	dfs(idx + 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int r, g, b; cin >> r >> g >> b;
		v.push_back({ r, g, b });
	}

	cin >> cr >> cg >> cb;
	dfs(0);

	cout << ans;
}