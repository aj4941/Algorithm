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
bool cache[200][200];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		int x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2; x1++; y1++;
		for (int x = x1; x <= x2; x++) for (int y = y1; y <= y2; y++)
			cache[x][y] = true;
	}

	int ans = 0;

	for (int i = 1; i <= 100; i++) for (int j = 1; j <= 100; j++)
	{
		if (cache[i][j])
			ans++;
	}

	cout << ans;
}