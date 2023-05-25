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
	string s; cin >> s;
	vector<pair<string, string>> v;

	v.push_back({ "NLCS", "North London Collegiate School" });
	v.push_back({ "BHA", "Branksome Hall Asia" });
	v.push_back({ "KIS", "Korea International School" });
	v.push_back({ "SJA", "St. Johnsbury Academy" });

	for (auto &to : v)
	{
		string a = to.second;
		string t = "";
		for (int i = 0; i < a.size(); i++)
		{
			if ('A' <= a[i] && a[i] <= 'Z')
				t += a[i] - 'A' + 'a';
			else if ('a' <= a[i] && a[i] <= 'z')
				t += a[i];

			if (t.size() == 10)
			{
				to.second = t;
				break;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < 26; n++)
		{
			string x = v[i].second;
			for (int j = 0; j < x.size(); j++)
			{
				int val = (x[j] - 'a' + n) % 26;
				char c = val + 'a';
				x[j] = c;
			}

			// cout << s << ' ' << x << endl;
			if (s == x)
			{
				cout << v[i].first;
				return 0;
			}
		}
	}
}