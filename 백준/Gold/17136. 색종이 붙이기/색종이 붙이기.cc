#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int min_ans = 1e9;
int paper_cnt[6] = { 0 };
int board[100][100] = { 0 };

void update(int x, int y, int s, int chk)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
			board[x + i][y + j] = chk;
	}
}

bool can_attach(int x, int y, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (!board[x + i][y + j])
				return false;
		}
	}
	return true;
}

void dfs(int x, int y, int cnt)
{
	bool hasP = false;
	int i, j;
	for (i = x; i < 10; i++)
	{
		for (j = y; j < 10; j++)
		{
			if (board[i][j] == 1)
			{
				hasP = true;
				break;
			}
		}
		y = 0;
		if (hasP) break;
	}
	if (min_ans <= cnt)
		return;
	if (!hasP)
	{
		min_ans = min(min_ans, cnt);
		return;
	}

	for (int s = 5; s > 0; s--)
	{
		if (i + s > 10 || j + s > 10 || paper_cnt[s] == 5) continue;
		if (can_attach(i, j, s))
		{
			update(i, j, s, 0);
			paper_cnt[s]++;
			dfs(i, j, cnt + 1);

			update(i, j, s, 1);
			paper_cnt[s]--;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
		cin >> board[i][j];
	dfs(0, 0, 0);
	if (min_ans == 1e9) min_ans = -1;
	cout << min_ans;
}