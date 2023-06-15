#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		int l = 0, r = n;
		bool flag = false;
		while (l + 1 < r)
		{
			int mid = (l + r) / 2;
			if (a[mid] < x) l = mid + 1;
			else if (a[mid] > x) r = mid;
			else
			{
				flag = true;
				break;
			}
		}
		if (flag || a[l] == x) cout << 1 << " ";
		else cout << 0 << " ";
	}
}