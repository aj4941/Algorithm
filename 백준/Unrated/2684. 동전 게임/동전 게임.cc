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
vector<string> s = { "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" };
map<string, int> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 0; i < 8; i++) mp[s[i]] = i;
	int t; cin >> t;
	while (t--)
	{
		vector<int> ans(8);
		string str; cin >> str;
		for (int i = 0; i < 40 - 2; i++)
		{
			string tmp = str.substr(i, 3);
			ans[mp[tmp]]++;
		}

		for (int i = 0; i < 8; i++)
			cout << ans[i] << ' ';
		cout << "\n";
	}
}