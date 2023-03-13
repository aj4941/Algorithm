#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
map<char, int> color;
int num[100];
vector<int> two_equal;
int three_equal = 0, four_equal = 0;
char five_equal_color = 'X';
int five_straight, mx_num;
char ch[4] = { 'R', 'B', 'Y', 'G' };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	vector<pair<int, char>> v;

	for (int i = 0; i < 5; i++)
	{
		char c; cin >> c;
		int x; cin >> x;
		color[c]++; num[x]++;
		mx_num = max(mx_num, x);
	}
	
	for (int i = 1; i <= 9; i++)
	{
		bool flag = true;
		for (int j = i; j < i + 5; j++)  // 5개 연속
		{
			if (num[j] == 0)
				flag = false;
		}
		if (flag)
			five_straight = i + 4;

		if (num[i] == 2) two_equal.push_back(i); // 2개 일치
		if (num[i] == 3) three_equal = i; // 3개 일치
		if (num[i] == 4) four_equal = i; // 4개 일치
	}

	for (int i = 0; i < 4; i++) // 5개 같은 색깔
	{
		if (color[ch[i]] == 5)
			five_equal_color = ch[i];
	}

	int ans = 0;

	if (five_equal_color != 'X' && five_straight) // 1
		ans = 900 + five_straight; \
	else if (four_equal) // 2
		ans = 800 + four_equal;
	else if (three_equal && two_equal.size()) // 3
		ans = 700 + three_equal * 10 + two_equal.back();
	else if (five_equal_color != 'X') // 4
		ans = 600 + mx_num;
	else if (five_straight) // 5
		ans = 500 + five_straight;
	else if (three_equal) // 6
		ans = 400 + three_equal;
	else if (two_equal.size() == 2) // 7
		ans = 300 + two_equal.back() * 10 + two_equal.front();
	else if (two_equal.size()) // 8
		ans = 200 + two_equal[0];
	else // 9
		ans = 100 + mx_num;

	cout << ans;
}