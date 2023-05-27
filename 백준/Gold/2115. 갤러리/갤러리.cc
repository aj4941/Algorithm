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
	int n, m; cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		ll ucnt = 0, dcnt = 0;

		for (int j = 0; j < m; j++)
		{
			if (i - 1 >= 0)
			{
				if (s[i][j] == 'X' && s[i - 1][j] == '.')
					ucnt++;
				else
				{
					ans += ucnt / 2;
					ucnt = 0;
				}
			}
			if (i + 1 < n)
			{
				if (s[i][j] == 'X' && s[i + 1][j] == '.')
					dcnt++;
				else
				{
					ans += dcnt / 2;
					dcnt = 0;
				}
			}
		}

		ans += ucnt / 2;
		ans += dcnt / 2;
	}

	for (int j = 0; j < m; j++)
	{
		
		ll lcnt = 0, rcnt = 0;

		for (int i = 0; i < n; i++)
		{
			if (j - 1 >= 0)
			{
				if (s[i][j] == 'X' && s[i][j - 1] == '.')
					lcnt++;
				else
				{
					ans += lcnt / 2;
					lcnt = 0;
				}
			}

			if (j + 1 < m)
			{
				if (s[i][j] == 'X' && s[i][j + 1] == '.')
					rcnt++;
				else
				{
					ans += rcnt / 2;
					rcnt = 0;
				}
			}
		}
		
		ans += lcnt / 2;
		ans += rcnt / 2;
	}

	cout << ans;
}