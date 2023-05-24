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
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
double x, y, c;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> x >> y >> c;
	double l = 0, r = 1e18;
	for (int i = 0; i < 10000; i++)
	{
		double mid = (l + r) / 2;
		double A = sqrt(x * x - mid * mid);
		double B = sqrt(y * y - mid * mid);
		double res = (A * B) / (A + B);
		if (res >= c) l = mid;
		else r = mid;
	}

	cout << fixed << setprecision(3) << l;
}