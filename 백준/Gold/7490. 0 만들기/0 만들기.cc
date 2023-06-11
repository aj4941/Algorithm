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
const int N = 20;
char prv[N];
char ch[3] = { '+', '-', ' ' };
int n;
vector<string> ans;

void dfs(int idx)
{
	if (idx == n)
	{
		ll sum = 0, val = 1, mod = 1;
		for (int i = 2; i <= n; i++)
		{
			if (prv[i - 1] == '+')
			{
				if (mod == 0) sum -= val;
				else sum += val;
				mod = 1; val = i;
			}
			else if (prv[i - 1] == '-')
			{
				if (mod == 0) sum -= val;
				else sum += val;
				mod = 0; val = i;
			}
			else
				val = val * 10 + i;
		}

		if (mod == 0) sum -= val;
		else sum += val;

		if (sum == 0)
		{
			string res = "1";
			for (int i = 2; i <= n; i++)
			{
				res += prv[i - 1];
				res += (i + '0');
			}
			ans.push_back(res);
		}
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		prv[idx] = ch[i];
		dfs(idx + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n; dfs(1);
		sort(ans.begin(), ans.end());
		for (auto to : ans)
			cout << to << "\n";

		cout << "\n";
		ans.clear();
	}
}