#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<ll, ll, ll> tl;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int cnt[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2,
					1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

string a, b;
vector<int> v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		v.push_back(cnt[a[i] - 'A']);
		v.push_back(cnt[b[i] - 'A']);
	}

	while (v.size() >= 3)
	{
		vector<int> nv;
		for (int i = 0; i < (int)v.size() - 1; i++)
			nv.push_back((v[i] + v[i + 1]) % 10);

		v = nv;
	}

	cout << v[0] << v[1];
}