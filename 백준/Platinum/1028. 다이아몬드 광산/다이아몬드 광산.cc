#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
#define INF 1000000007
int n, m;
string s[1000];
int UL[802][802], UR[802][802], DL[802][802], DR[802][802];
int ans = 0;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		int ni = i - 1, nj = j - 1;
		if (ni < 0 || nj < 0 || ni >= n || nj >= m)
		{
			UL[i][j] = (s[i][j] == '1') ? 1 : 0;
			continue;
		}
		if (s[i][j] == '0') UL[i][j] = 0;
		else UL[i][j] = UL[ni][nj] + 1;
	}
	for (int i = 0; i < n; i++) for (int j = m - 1; j >= 0; j--)
	{
		int ni = i - 1, nj = j + 1;
		if (ni < 0 || nj < 0 || ni >= n || nj >= m)
		{
			UR[i][j] = (s[i][j] == '1') ? 1 : 0;
			continue;
		}
		if (s[i][j] == '0') UR[i][j] = 0;
		else UR[i][j] = UR[ni][nj] + 1;
	}
	for (int i = n - 1; i >= 0; i--) for (int j = 0; j < m; j++)
	{
		int ni = i + 1, nj = j - 1;
		if (ni < 0 || nj < 0 || ni >= n || nj >= m)
		{
			DL[i][j] = (s[i][j] == '1') ? 1 : 0;
			continue;
		}
		if (s[i][j] == '0') DL[i][j] = 0;
		else DL[i][j] = DL[ni][nj] + 1;
	}
	for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--)
	{
		int ni = i + 1, nj = j + 1;
		if (ni < 0 || nj < 0 || ni >= n || nj >= m)
		{
			DR[i][j] = (s[i][j] == '1') ? 1 : 0;
			continue;
		}
		if (s[i][j] == '0') DR[i][j] = 0;
		else DR[i][j] = DR[ni][nj] + 1;
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (s[i][j] == '0') continue;
		for (int k = 1; k <= min(UR[i][j], DR[i][j]); k++)
		{
			int ni = i, nj = j + 2 * (k - 1);
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (UL[ni][nj] >= k && DL[ni][nj] >= k)
				ans = max(ans, k);
		}
	}
	cout << ans;
}