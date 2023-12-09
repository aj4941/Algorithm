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

bool cmp(string &a, string &b)
{
	if (a.size() != b.size()) 
		return a.size() < b.size();
	int acnt = 0, bcnt = 0;
	for (auto to : a)
	{
		if (to >= '0' && to <= '9') 
			acnt += to - '0';
	}
	for (auto to : b)
	{
		if (to >= '0' && to <= '9')
			bcnt += to - '0';
	}
	if (acnt != bcnt)
		return acnt < bcnt;

	return a < b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<string> st(n);
	for (int i = 0; i < n; i++) cin >> st[i];
	sort(st.begin(), st.end(), cmp);
	for (auto to : st) cout << to << "\n";
}