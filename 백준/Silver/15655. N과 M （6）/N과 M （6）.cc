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
int n, m;
vector<int> a;
int prv[N];

// 1. 선택
// 2. 패스

void dfs(int idx, int cnt) // 원소, 선택개수
{
	if (cnt == m) // 완성
	{
		for (int i = 1; i <= m; i++)
			cout << prv[i] << ' ';
		cout << "\n";
		return;
	}
	
	if (idx == n)
		return;

	prv[cnt + 1] = a[idx + 1]; // 선택
	dfs(idx + 1, cnt + 1);

	dfs(idx + 1, cnt); // 패스
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	dfs(0, 0);
}