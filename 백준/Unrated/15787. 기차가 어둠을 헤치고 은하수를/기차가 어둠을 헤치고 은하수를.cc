#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n, m;
vector<vector<int>> v;
set<vector<int>> st;
int N = 20;

void l_func(vector<int>& v)
{
	for (int i = 1; i < N; i++)
		v[i - 1] = v[i];
	v[N - 1] = 0;
}

void r_func(vector<int>& v)
{
	for (int i = N - 2; i >= 0; i--)
		v[i + 1] = v[i];
	v[0] = 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		v.push_back({});
		for (int j = 0; j < N; j++)
			v.back().push_back(0);
	}

	for (int i = 0; i < m; i++)
	{
		int c, idx;
		cin >> c >> idx; idx--;
		if (c == 1)
		{
			int x; cin >> x; x--;
			v[idx][x] = 1;
		}
		else if (c == 2)
		{
			int x; cin >> x; x--;
			v[idx][x] = 0;
		}
		else if (c == 3) r_func(v[idx]);
		else l_func(v[idx]);
	}

	for (int i = 0; i < n; i++)
		st.insert(v[i]);

	cout << st.size();
}