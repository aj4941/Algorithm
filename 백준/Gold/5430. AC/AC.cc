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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		string cmd; cin >> cmd;
		int n; cin >> n;
		string t, w; cin >> t;
		string s = t.substr(1); s.pop_back();

		deque<int> dq;
		stringstream sr(s);
		while (getline(sr, w, ','))
		{
			dq.push_back(stoi(w));
		}

		bool rev = false;
		bool hasAns = true;

		for (int i = 0; i < cmd.size(); i++)
		{
			if (cmd[i] == 'R')
				rev = !rev;
			else 
			{
				if (dq.size() == 0)
				{
					hasAns = false;
					break;
				}
				if (rev)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}

		if (!hasAns)
			cout << "error" << "\n";
		else
		{
			if (rev)
				reverse(dq.begin(), dq.end());

			cout << "[";
			while (dq.size())
			{
				cout << dq.front();
				dq.pop_front();
				if (dq.size()) cout << ",";
			}
			cout << "]" << "\n";
		}
	}
}