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
const int N = 200;
int cnt[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	vector<pii> tmp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			tmp.push_back({ a[i] * b[j], j });
	}

	sort(tmp.rbegin(), tmp.rend());

	ll ans = -1;

	for (auto to : tmp)
	{
		int idx = to.second;
		if (cnt[idx] == 0)
		{
			cnt[idx] = 1;
			k--;

			if (k < 0)
			{
				ans = to.first;
				break;
			}
		}
	}

	cout << ans;
}