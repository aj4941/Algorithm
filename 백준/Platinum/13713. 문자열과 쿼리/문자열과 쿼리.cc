#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000007
const int N = 1000002;
int Z[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s; cin >> s;
	reverse(s.begin(), s.end());
	int L = 0, R = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (i > R)
		{
			L = R = i;
			while (R < s.size() && s[R - L] == s[R]) R++;
			Z[i] = R - L; R--;
		}
		else
		{
			int K = i - L;
			if (Z[K] < R - i + 1) Z[i] = Z[K];
			else
			{
				L = i;
				while (R < s.size() && s[R - L] == s[R]) R++;
				Z[i] = R - L; R--;
			}
		}
	}
	Z[0] = s.size();
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		cout << Z[s.size() - x] << "\n";
	}
}