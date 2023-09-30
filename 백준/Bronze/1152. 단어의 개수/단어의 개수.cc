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
	string str; getline(cin, str);
	ll n = str.size();
	ll ans = 0;
	for (ll i = 0; i < n; i++) if (str[i] == ' ') ans++;
	if (str[0] == ' ') ans--;
	if (str[n - 1] == ' ') ans--;
	cout << ans + 1;
}