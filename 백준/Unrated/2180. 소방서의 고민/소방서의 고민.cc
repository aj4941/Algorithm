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
vector<pll> v;
ll n, t;
const ll mod = 40000;

bool cmp(pll a, pll b)
{
	if (a.first == 0) return false;
	if (b.first == 0) return true;
	return b.first * a.second < a.first * b.second;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll a, b; cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		ll a = v[i].first, b = v[i].second;
		t += a * t + b; t %= mod;
	}

	cout << t;
}
