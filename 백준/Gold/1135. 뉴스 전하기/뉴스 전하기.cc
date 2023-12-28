#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
const ll N = 100;
vector<ll> g[N];
ll n; 

ll solve(ll v)
{
	ll res = 0;
	vector<ll> tmp;
	for (ll nv : g[v]) tmp.push_back(solve(nv));
	sort(tmp.rbegin(), tmp.rend());
	for (ll i = 0; i < tmp.size(); i++)
		res = max(res, tmp[i] + (i + 1));

	return res;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;

	for (ll i = 0; i < n; i++)
	{
		ll v; cin >> v;
		if (v == -1) continue;
		g[v].push_back(i);
	}

	cout << solve(0);
}