#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000000

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	bool flag = false;
	vector<int> res;
	int id = -1;
	for (int i = n - 1; i > 0; i--)
	{
		res.push_back(a[i]);
		if (a[i] > a[i - 1])
		{
			res.push_back(a[i - 1]);
			id = i - 1;
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < id; i++) cout << a[i] << ' ';
	sort(res.begin(), res.end());
	int x = upper_bound(res.begin(), res.end(), a[id]) - res.begin();
	cout << res[x] << ' ';
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] != res[x])
			cout << res[i] << ' ';
	}

}