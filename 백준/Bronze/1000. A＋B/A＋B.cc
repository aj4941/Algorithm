#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int gcd(int a, int b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 502;
int dist[N][N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	map<pair<int, int>, int> mp;
	for (int i = 0; i < 100000; i++)
	{
		mp[{ i, i }] = i;
	}
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
		for (int k = 0; k < 3; k++) for (int l = 0; l < 3; l++)
		{
			for (int x = 0; x < 100000; x++)
			{
				int value = mp[{ x, x }];
			}
		}
	int a, b; cin >> a >> b;
	cout << a + b;


}