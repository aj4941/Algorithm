#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
#define INF 1000000007

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> x(n + 1);
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (n == 1)
	{
		cout << "A";
		return 0;
	}
	else if (n == 2)
	{
		if (x[1] == x[2])
			cout << x[1];
		else
			cout << "A";
		return 0;
	}
	else
	{
		int a = -1, b = -1;
		if (x[1] == x[2])
		{
			if (x[2] == x[3])
				a = 1, b = 0;
			else
			{
				cout << "B";
				return 0;
			}
		}
		else
		{
			if (abs(x[2] - x[3]) % abs(x[1] - x[2]))
			{
				cout << "B";
				return 0;
			}
			a = (x[2] - x[3]) / (x[1] - x[2]);
			b = x[2] - a * x[1];
		}
		bool hasAns = true;
		for (int i = 4; i <= n; i++)
		{
			if (x[i] != x[i - 1] * a + b)
				hasAns = false;
		}
		if (hasAns)
			cout << x[n] * a + b;
		else
			cout << "B";
	}
}