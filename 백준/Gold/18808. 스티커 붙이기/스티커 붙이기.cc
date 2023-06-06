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
		// ans 보드에서는 (i, j) 이지만 스티커 입장에서는 무조건 (0, 0)에서 두는 것이므로 (i - x, j - y)로 탐색해야 한다.
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
		b[j][r - 1 - i] = a[t][i][j]; // (x, y) -> (y, n - 1 - x) 로 변하는 것을 관찰할 수 있다.
		a[t][i][j] = 0; // 여기서 보드에 덧칠되는 스티커가 바뀌므로 0으로 리셋이 필요하다.
	}

	swap(r, c); // 90도 회전하면 r * c -> c * r로 바뀌는 것에 주의하자.

	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
		a[t][i][j] = b[i][j]; // 90도 회전된 결과를 그대로 a에 복사한다.
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
		for (int mv = 0; mv < 4; mv++) // 0, 1, 2, 3 이 회전수이므로 mv < 3이 아니라 mv < 4로 둬야 함
		{
			// printSticker(t);
			bool hasAns = false;
			for (int x = 0; x < n && !hasAns; x++) for (int y = 0; y < m && !hasAns; y++)
			{
				if (x + r - 1 >= n || y + c - 1 >= m) // 범위 초과 체크는 x + r이 아니라 x + r - 1이다. (x를 길이 1로 보므로)
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