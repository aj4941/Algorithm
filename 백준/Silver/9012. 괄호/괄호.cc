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
		string s; cin >> s;
		int cnt = 0;
		bool hasAns = true;
		for (auto to : s)
		{
			if (to == '(') cnt++;
			else cnt--;

			if (cnt < 0)
				hasAns = false;
		}

		if (cnt != 0)
			hasAns = false;

		if (hasAns) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}