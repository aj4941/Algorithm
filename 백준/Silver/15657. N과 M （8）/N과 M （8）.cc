#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, -1, -1, 0 };
int dy[4] = { -1, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 10;
int cache[N];
int n, m;
vector<int> a, tmp;
// 1. 원소 하나를 올리거나
// 2. 현재 원소를 택하거나

void dfs(int idx, int st, int cnt) 
{
	if (cnt == m) 
	{
		for (int i = 0; i < m; i++)
			cout << a[cache[i]] << ' ';
		cout << "\n";
	}

	if (idx == n)
		return;

	for (int i = st; i < n; i++)
	{
		cache[idx] = i;
		dfs(idx + 1, i, cnt + 1);
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

	dfs(0, 0, 0);
}