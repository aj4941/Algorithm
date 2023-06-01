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
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 5002;
string s;
vector<string> v = { "pi", "ka", "chu" };
bool hasAns = false;
bool cache[N];

void dfs(int i)
{
	if (cache[i]) return;
	cache[i] = true;
	if (i == s.size())
	{
		hasAns = true;
		return;
	}

	string r1 = s.substr(i, 2);
	string r2 = s.substr(i, 3);

	if (r1 == v[0] || r1 == v[1])
		dfs(i + 2);

	if (r2 == v[2])
		dfs(i + 3);
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;

	dfs(0);

	if (hasAns) cout << "YES";
	else cout << "NO";
}