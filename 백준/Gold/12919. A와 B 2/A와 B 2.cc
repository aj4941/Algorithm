#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int gcd(int a, int b) { for (; b; a %= b, swap(a, b)); return a; }
string s, t;

int dfs(string tmp)
{
	int ans = 0; // 초기에는 정답을 0으로 설정
	if (tmp == s) return 1; // s 문자열에 도달하면 정답이므로 1을 반환
	if (s.size() > tmp.size()) return 0; // tmp 크기가 더 작아지면 정답이 될 수 없으므로 0 반환
    
	if (tmp.back() == 'A') // A 제거
	{
		tmp.pop_back(); 
		ans |= dfs(tmp);
		tmp.push_back('A');
	}
    
	if (tmp.front() == 'B') // B 제거
	{
		reverse(tmp.begin(), tmp.end()); // 뒤집은 후
		tmp.pop_back(); // 앞에 있던 B가 뒤로 오므로 B를 pop_back 처리
		ans |= dfs(tmp);
	}
    
	return ans;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s >> t;
	cout << dfs(t);
}