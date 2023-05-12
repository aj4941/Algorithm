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
const ll inf = 1000000009;
const ll N = 50002;
ll n;
ll dp[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	dp[1] = 1;
	for (ll i = 2; i < N; i++)
	{
		dp[i] = (2 * i - 1) * dp[i - 1];
		dp[i] %= inf;
	}
	
	ll n; cin >> n;
	cout << dp[n];
}