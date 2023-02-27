#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

void move(ll& a, ll& b, ll& c)
{
	b--;
	a = c = (a - b) / 2;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	if (n <= 3)
	{
		if (n == 1) cout << 'm';
		else cout << 'o';
		return 0;
	}
	ll a = 0, b = 3, c = 0;
	while (a + b + c < n)
	{
		a = c = (a + b + c);
		b++;
	}
	
	while (true)
	{
		if (n <= a) move(a, b, c);
		else if (a < n && n <= a + b)
		{
			n -= a;
			if (n == 1) cout << 'm';
			else cout << 'o';
			return 0;
		}
		else
		{
			n -= (a + b);
			move(a, b, c);
		}
	}
}