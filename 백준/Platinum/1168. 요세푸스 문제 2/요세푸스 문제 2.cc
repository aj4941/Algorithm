#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[8] = { -1, 1, 0, 0, 1, 1, 0, -1 };
int dy[8] = { 0, 0, 1, -1, 0, -1, -1, -1 };
#define INF 1000000007
const int N = 100002;
int segTree[N * 4];

void update(int ptr, int s, int e, int i, int val)
{
	if (i < s || e < i)
		return;
	if (s == e)
	{
		segTree[ptr] = val;
		return;
	}
	update(ptr * 2, s, (s + e) / 2, i, val);
	update(ptr * 2 + 1, (s + e) / 2 + 1, e, i, val);
	segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}

int getVal(int ptr, int s, int e, int k)
{
	if (s == e)
		return s;
	if (segTree[ptr * 2] >= k)
		return getVal(ptr * 2, s, (s + e) / 2, k);
	else
		return getVal(ptr * 2 + 1, (s + e) / 2 + 1, e, k - segTree[ptr * 2]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)  
		update(1, 0, n - 1, i, 1);

	int tmp = k - 1, total = n;
	cout << "<";
	while (true)
	{
		int val = getVal(1, 0, n - 1, tmp + 1);
		cout << val + 1;
		update(1, 0, n - 1, val, 0);
		total--;
		if (total == 0) break;
		cout << ", ";
		tmp %= total; 
		tmp += (k - 1); 
		tmp %= total;
	}
	cout << ">";
}