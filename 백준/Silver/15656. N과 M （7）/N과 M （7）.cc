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
const int N = 20;
int prv[N];
int n, m;
vector<int> a, stk;

void dfs(int idx, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < stk.size(); i++)
			cout << stk[i] << ' ';
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		stk.push_back(a[i]);
		dfs(i, cnt + 1);
		stk.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	dfs(0, 0);
}