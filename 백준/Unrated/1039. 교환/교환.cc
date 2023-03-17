#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 1000002;
ll n, k;
bool cache[N][12];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	queue<pii> q;
	q.push({ n, 0 }); cache[n][0] = true;

	while (!q.empty())
	{
		ll x = q.front().first, c = q.front().second; q.pop();
		if (c == k) continue;
		string s = to_string(x);
		ll sz = s.size();
		for (int i = 0; i < sz; i++)
		{
			for (int j = i + 1; j < sz; j++)
			{
				if (i == 0 && s[j] == '0') continue;
				swap(s[i], s[j]);
				ll nx = stoll(s);
				if (!cache[nx][c + 1])
				{
					q.push({ nx, c + 1 });
					cache[nx][c + 1] = true;
				}
				swap(s[i], s[j]);
			}
		}
	}

	ll ans = -1;

	for (int num = 1; num < N; num++)
	{
		if (cache[num][k])
			ans = num;
	}

	cout << ans;
}