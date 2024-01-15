#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
#define MOD 1000000007
string s, t;
int n, cnt = 0;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		t += c;
	}
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		s += c;
	}
	s += s; s.pop_back();
	int j = 0;
	vector<int> table(t.size(), 0);
	for (int i = 1; i < t.size(); i++)
	{
		while (j != 0 && t[i] != t[j])
			j = table[j - 1];

		if (t[i] == t[j])
			table[i] = ++j;
	}
	j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (j != 0 && s[i] != t[j])
			j = table[j - 1];

		if (j == t.size() - 1)
		{
			cnt++;
			j = table[j];
		}
		else
			j++;
	}
	int g = gcd(cnt, n);
	cnt /= g; n /= g;
	cout << cnt << "/" << n;
}