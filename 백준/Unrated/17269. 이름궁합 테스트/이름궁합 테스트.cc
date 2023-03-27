#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int cnt[26] = { 3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int n, m;
string a, b;
vector<int> res, tmp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> a >> b;
	int i = 0, j = 0;
	while (i < a.size() || j < b.size())
	{
		if (i < a.size())
			res.push_back(cnt[a[i++] - 'A']);
		if (j < b.size())
			res.push_back(cnt[b[j++] - 'A']);
	}

	while (res.size() > 2)
	{
		vector<int> tmp;
		for (int i = 0; i < (int)res.size() - 1; i++)
			tmp.push_back((res[i] + res[i + 1]) % 10);

		res = tmp;
	}

	if (res[0] == 0)
		cout << res[1] << "%";
	else
		cout << res[0] << res[1] << "%";
}