#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1110987654321

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int cnt = 0;
	deque<int> dq;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		int idx;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == x)
			{
				idx = i;
				break;
			}
		}
		if (idx < dq.size() - idx)
		{
			while (true)
			{
				if (dq.front() == x)
				{
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			while (true)
			{
				if (dq.front() == x)
				{
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	cout << cnt;
}