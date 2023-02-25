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
	int st = 0;
	for (int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
	{
		int num; cin >> num;
		if (num == 0) num = 9;
		st = st * 10 + num;
	}
	queue<int> q; 
	map<int, int> cache;
	q.push(st); cache[st] = 0;
	
	while (!q.empty())
	{
		int cur = q.front();
		string s = to_string(cur); q.pop();
		if (cur == 123456789) break;
		int pos = s.find('9');
		int x = pos / 3, y = pos % 3;
		for (int i = 0; i < 4; i++)
		{
			int cx = x + dx[i], cy = y + dy[i];
			if (cx < 0 || cy < 0 || cx >= 3 || cy >= 3) continue;
			string tmp = s;
			swap(tmp[x * 3 + y], tmp[cx * 3 + cy]);
			int next = stoi(tmp);
			if (!cache.count(next))
			{
				cache[next] = cache[cur] + 1;
				q.push(next);
			}
		}
	}
	if (cache.count(123456789))
		cout << cache[123456789];
	else
		cout << -1;
}