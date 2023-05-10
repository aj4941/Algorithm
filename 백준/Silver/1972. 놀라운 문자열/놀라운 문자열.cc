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
	while (true)
	{
		string s; cin >> s;
		if (s == "*") break;
		int n = s.size();
		bool hasAns = true;

		for (int k = 1; k < n; k++)
		{
			map<string, int> mp;
			for (int i = 0; i < n; i++)
			{
				int j = i + k;
				if (j >= n) break;
				string t = string("") + s[i] + s[j];
				mp[t]++;
			}

			for (auto to : mp)
			{
				if (to.second >= 2)
					hasAns = false;
			}

			if (!hasAns)
				break;
		}

		cout << s << ' ';
		if (hasAns) cout << "is surprising.";
		else cout << "is NOT surprising.";
		cout << "\n";
	}
}