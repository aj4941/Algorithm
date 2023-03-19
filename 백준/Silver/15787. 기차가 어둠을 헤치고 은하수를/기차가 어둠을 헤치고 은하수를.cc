#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100050;
const int MAX = (1 << 20);
int n, m, bit[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int c; cin >> c;
		if (c == 1)
		{
			int idx, x; cin >> idx >> x; x--;
			bit[idx] |= (1 << x);
		}
		else if (c == 2)
		{
			int idx, x; cin >> idx >> x; x--;
			bit[idx] &= (MAX - 1 - (1 << x));
		}
		else if (c == 3)
		{
			int idx; cin >> idx;
			bit[idx] <<= 1; bit[idx] %= MAX;
		}
		else // c == 4
		{
			int idx; cin >> idx;
			bit[idx] >>= 1;
		}
	}

	set<int> st;

	for (int i = 1; i <= n; i++)
		st.insert(bit[i]);

	cout << st.size();
}