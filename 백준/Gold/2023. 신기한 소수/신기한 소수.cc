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
int n;
vector<int> ans;

bool calc(int num)
{
	if (num == 0 || num == 1)
		return false;

	bool hasAns = true;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			hasAns = false;
	}

	return hasAns;
}

void dfs(int cnt, int num)
{
	if (cnt == n)
	{
		ans.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		int tmp = num * 10 + i;
		if (calc(tmp)) dfs(cnt + 1, tmp);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	dfs(0, 0);

	for (auto to : ans)
		cout << to << "\n";
}