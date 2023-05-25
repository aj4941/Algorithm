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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k; m--;
	int ck = 3;

	if (k > 3)
	{
		while (ck != k)
		{
			m = (m + 1) % n;
			ck++;
		}
	}
	else
	{
		while (ck != k)
		{
			m = (m - 1 + n) % n;
			ck--;
		}
	}

	cout << m + 1;
}