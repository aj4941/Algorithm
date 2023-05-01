#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, -1, -1, 0 };
int dy[4] = { -1, 0, 1, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int cnt[30];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s; cin >> s;
	for (auto to : s) cnt[to - 'A']++;

	int odd = 0;
	int odd_val = -1;

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] % 2)
		{
			odd++;
			odd_val = i;
		}
	}

	if (odd >= 2)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	vector<int> a, b;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < cnt[i] / 2; j++)
		{
			a.push_back(i);
			b.push_back(i);
		}
	}
	
	if (odd_val != -1) 
		b.push_back(odd_val);

	reverse(b.begin(), b.end());
	string ans = "";

	for (auto to : a) ans += to + 'A';
	for (auto to : b) ans += to + 'A';

	cout << ans;
}