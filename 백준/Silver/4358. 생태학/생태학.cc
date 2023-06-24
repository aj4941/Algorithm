#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1000000007
double n = 0;
vector<pair<string, double>> ans;

struct Node
{
	double cnt = 0;
	Node* child[200] = { 0 };
} *Trie;

void solve(Node* curNode, string st)
{
	if (curNode->cnt != 0)
		ans.push_back({ st, curNode->cnt / n * 100 });
	for (int i = 0; i < 200; i++)
	{
		if (curNode->child[i] != 0)
			solve(curNode->child[i], st + (char)i);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	Trie = new Node;
	string s;
	while (getline(cin, s))
	{
		n++;
		Node* curNode = Trie;
		for (char c : s)
		{
			int idx = (int)c;
			if (curNode->child[idx] == 0)
				curNode->child[idx] = new Node;
			curNode = curNode->child[idx];
		}
		curNode->cnt++;
	}
	solve(Trie, "");
	sort(ans.begin(), ans.end());
	for (auto to : ans)
	{
		cout << to.first << ' ';
		cout << fixed << setprecision(4) << to.second;
		cout << "\n";
	}
}