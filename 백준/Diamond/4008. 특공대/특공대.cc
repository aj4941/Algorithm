#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[6] = { 0, 0, 1, -1, -1, -1 };
int dy[6] = { 1, -1, 0, 0, -1, 1 };
#define MOD 1000000007
const int N = 1000002;
int n;
ll a[N], p[N], dp[N];
ll A, B, C;

struct line {
	ll a, b;
	double x;
	line(ll a1, ll b1, double x1 = 0) : a(a1), b(b1), x(x1) { }
};

double cross(line a, line b)
{
	return (b.b - a.b) / (a.a - b.a);
}
vector<line> stk;

ll f(ll x)
{
	return A * x * x + B * x + C;
}

ll A_(int i)
{
	return -2ll * A * p[i];
}

ll C_(int i)
{
	return A * p[i] * p[i] - B * p[i] + dp[i];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> A >> B >> C;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
	dp[1] = f(p[1]);
	for (int i = 1; i <= n - 1; i++)
	{
		line g(A_(i), C_(i));
		while (stk.size() > 0)
		{
			g.x = cross(g, stk.back());
			if (g.x < stk.back().x)
				stk.pop_back();
			else
				break;
		}
		stk.push_back(g);
		ll x = p[i + 1];
		ll l = 0, r = stk.size();
		while (l + 1 < r)
		{
			ll m = (l + r) / 2;
			if (stk[m].x < x) l = m;
			else r = m;
		}
		dp[i + 1] = max(f(x), stk[l].a * x + stk[l].b + f(x));
	}
	cout << dp[n];
}