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
const int N = (1 << 20) + 5;
bool cache[N];
int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int cx; cin >> cx;
		int pos = 0, x = cx;
		while (x > 1)
		{
			if (cache[x]) pos = x;
			x /= 2;
		}

		cout << pos << "\n";

		cache[cx] = true;
	}
}