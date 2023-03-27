#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 2005;
bool cache[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int x, y; cin >> x >> y;
	int ans = 0;

	for (int i = x; i <= y; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int g = gcd(i, j);
			int cj = j / g, ci = i / g;
			if (!cache[cj][ci]) ans++;
			cache[cj][ci] = true;
		}
	}

	cout << ans;
}