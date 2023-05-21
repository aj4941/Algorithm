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

int n, temp, visited[7];
vector<int> v;

void dfs(int d, int sum) {
	if (d == v.size()) {
		if (sum > n) {
			cout << sum << "\n";
			exit(0);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(d + 1, sum * 10 + v[i]);
			visited[i] = false;
		} 
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	temp = n;
	while (temp) {
		v.push_back(temp % 10);
		temp /= 10;
	}
	sort(v.begin(), v.end());
	
	dfs(0, 0);

	cout << "0\n";
	return 0;
}