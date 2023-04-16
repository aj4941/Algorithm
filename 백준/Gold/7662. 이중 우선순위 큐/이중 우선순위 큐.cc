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
	int t; cin >> t;
	while (t--)
	{
		priority_queue<pll> mx, mn;
		ll n; cin >> n;
		vector<bool> cache(n, false);

		for (int i = 0; i < n; i++)
		{
			char c; cin >> c;
			ll x; cin >> x;
			if (c == 'I')
			{
				mx.push({ x, i }); mn.push({ -x, -i });
				cache[i] = true;
			}
			else
			{
				if (x == 1) // max
				{
					while (!mx.empty() && !cache[mx.top().second]) mx.pop();
					if (mx.size())
					{
						int idx = mx.top().second;
						cache[idx] = false;
						mx.pop();
					}
				}
				else // min
				{
					while (!mn.empty() && !cache[-mn.top().second]) mn.pop();
					if (mn.size())
					{
						int idx = -mn.top().second;
						cache[idx] = false;
						mn.pop();
					}
				}
			}
		}

		while (!mx.empty() && !cache[mx.top().second]) mx.pop();
		while (!mn.empty() && !cache[-mn.top().second]) mn.pop();

		if (mx.size() == 0 && mn.size() == 0)
			cout << "EMPTY" << "\n";
		else
			cout << mx.top().first << ' ' << -mn.top().first << "\n";
	}
}