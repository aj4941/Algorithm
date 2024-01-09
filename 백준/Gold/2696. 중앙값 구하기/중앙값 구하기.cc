#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll t; cin >> t;
	while (t--)
	{
		vector<ll> ans;
		priority_queue<ll> l, r;
		ll n; cin >> n;
		for (ll i = 0; i < n; i++)
		{
			ll x; cin >> x;
			if (l.size() == r.size())
				l.push(x);
			else
				r.push(-x);

			if (i % 2 == 0)
			{
				if (i == 0)
					ans.push_back(l.top());
				else
				{
					ll lval = l.top(), rval = -r.top();
					if (lval > rval)
					{
						l.pop(); r.pop();
						l.push(rval); r.push(-lval);
					}
					ans.push_back(l.top());
				}
			}
		}

		cout << ans.size() << "\n";
		for (ll i = 0; i < ans.size(); i++)
		{
			if (i % 10 == 0 && i > 0) cout << "\n";
			cout << ans[i] << ' ';
			
		}
		cout << "\n";
	}
}