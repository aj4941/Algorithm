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
int n, m, k;
int a[102][20][20];
int ans[100][100];
vector<pii> p;

bool putSticker(int t, int x, int y, int r, int c)
{
	bool flag = true;
	for (int i = x; i < x + r; i++) for (int j = y; j < y + c; j++)
	{
		if (ans[i][j] && a[t][i - x][j - y])
		{
			flag = false;
			break;
		}
	}

	if (flag)
	{
		// cout << "success : " << t << ' ' << x << ' ' << y << endl;
		for (int i = x; i < x + r; i++)
		{
			for (int j = y; j < y + c; j++)
				ans[i][j] |= a[t][i - x][j - y];
		}
			
	}

	return flag;
}

void move(int t, int &r, int &c)
{
	int b[20][20] = { 0 };
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
	{
		b[j][r - 1 - i] = a[t][i][j];
		a[t][i][j] = 0;
	}

	swap(r, c);

	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
		a[t][i][j] = b[i][j];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;

	for (int t = 0; t < k; t++)
	{
		int r, c; cin >> r >> c;
		p.push_back({ r, c });
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
			cin >> a[t][i][j];
	}

	for (int t = 0; t < k; t++)
	{
		// print();
		int r = p[t].first, c = p[t].second;
		for (int mv = 0; mv < 4; mv++) 
		{
			// printSticker(t);
			bool hasAns = false;
			for (int x = 0; x < n && !hasAns; x++) for (int y = 0; y < m && !hasAns; y++)
			{
				if (x + r - 1 >= n || y + c - 1 >= m)
					continue;

				if (putSticker(t, x, y, r, c))
				{
					hasAns = true;
					break;
				}
			}
			if (hasAns) break;
			move(t, r, c);
		}
	}

	int res = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (ans[i][j])
			res++;
	}

	cout << res;
}