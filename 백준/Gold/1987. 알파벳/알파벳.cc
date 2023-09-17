#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 121110987654321
ll r, c;
string a[20];
ll ans = 0;
ll alpha[26] = { 0 };

void solve(ll x, ll y, ll cnt, ll alpha[26])
{
	ans = max(ans, cnt);
	for (ll i = 0; i < 4; i++)
	{
		ll cx = x + dx[i], cy = y + dy[i];
		if (cx < 0 || cx >= r || cy < 0 || cy >= c) continue;
		if (alpha[a[cx][cy] - 'A'] == 0)
		{
			alpha[a[cx][cy] - 'A']++;
			solve(cx, cy, cnt + 1, alpha);
			alpha[a[cx][cy] - 'A']--;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> r >> c;
	for (ll i = 0; i < r; i++)
		cin >> a[i];
	alpha[a[0][0] - 'A']++;
	solve(0, 0, 1, alpha);
	cout << ans;
}