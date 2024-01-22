#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1098765432111

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string st; cin >> st;
	ll mx = 0, mx_cnt = 0, n = st.size();
	char mx_val;
	map<char, ll> mp;
	for (ll i = 0; i < n; i++)
	{
		if (st[i] >= 'a') st[i] -= 32;
		mp[st[i]]++;
		if (mx == mp[st[i]]) mx_cnt++;
		else if (mx < mp[st[i]])
		{
			mx = mp[st[i]];
			mx_val = st[i];
			mx_cnt = 1;
		}
	}
	if (mx_cnt > 1) cout << "?";
	else cout << mx_val;
}