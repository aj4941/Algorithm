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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll r, g; cin >> r >> g;
	ll G = gcd(r, g);
	vector<tl> ans;

	for (ll i = 1; i * i <= G; i++)
	{
		if (G % i == 0)
			ans.push_back({ i, r / i, g / i });
		if (i != G / i && G % (G / i) == 0)
			ans.push_back({ G / i, r / (G / i), g / (G / i) });
	}

	for (auto to : ans)
		cout << get<0>(to) << ' ' << get<1>(to) << ' ' << get<2>(to) << "\n";
}