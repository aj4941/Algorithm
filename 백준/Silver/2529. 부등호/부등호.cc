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
vector<char> ch;
string mn = "", mx = "";
bool cache[20];
int p[20];

void dfs(int idx)
{
	if (idx == ch.size() + 1)
	{
		bool hasAns = true;
		string res = "";
		for (int i = 0; i <= ch.size(); i++)
		{
			res += (p[i] + '0');
			if (i < ch.size())
			{
				if (ch[i] == '<')
				{
					if (p[i] < p[i + 1]) continue;
					else hasAns = false;
				}
				else
				{
					if (p[i] > p[i + 1]) continue;
					else hasAns = false;
				}
			}
		}

		if (!hasAns) return;

		if (mn == "") mn = res;
		else mn = min(mn, res);

		if (mx == "") mx = res;
		else mx = max(mx, res);

		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (cache[i]) continue;
		p[idx] = i; cache[i] = true;
		dfs(idx + 1);
		cache[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	ch.resize(n);
	for (int i = 0; i < n; i++) cin >> ch[i];
	dfs(0);

	cout << mx << "\n" << mn;
}