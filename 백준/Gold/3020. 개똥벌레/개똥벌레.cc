#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 500006;
int cnt[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, h; cin >> n >> h;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (i % 2 == 0) cnt[1]++, cnt[x + 1]--;
		else cnt[h - (x - 1)]++, cnt[h + 1]--;
	}

	for (int i = 1; i <= h; i++) cnt[i] += cnt[i - 1];

	int mx = 1e9, res = 0;

	for (int i = 1; i <= h; i++)
	{
		if (mx == cnt[i])
			res++;
		else if (cnt[i] < mx)
		{
			mx = cnt[i];
			res = 1;
		}
	}

	cout << mx << ' ' << res;
}