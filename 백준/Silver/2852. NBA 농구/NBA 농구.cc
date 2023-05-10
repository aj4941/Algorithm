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
int cache[48 * 60 + 5];

void print(int t)
{
	if (t / 60 < 10) cout << 0;
	cout << t / 60;

	cout << ":";

	if (t % 60 < 10) cout << 0;
	cout << t % 60;

	cout << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int c; cin >> c;
		string s; cin >> s;
		int num = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
		cache[num] = c;
	}

	int sc1 = 0, sc2 = 0;
	int t1 = 0, t2 = 0;

	for (int t = 0; t <= 48 * 60; t++)
	{
		if (sc1 < sc2) t2++;
		if (sc1 > sc2) t1++;

		if (cache[t] == 1) sc1++;
		if (cache[t] == 2) sc2++;
	}

	print(t1); print(t2);
}