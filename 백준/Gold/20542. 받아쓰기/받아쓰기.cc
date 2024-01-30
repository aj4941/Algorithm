#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<vector<int>> dp;
int n, m;
string s, t;

bool equal(char a, char b)
{
    if (a == b)
        return true;
    if (a == 'i' && (b == 'i' || b == 'j' || b == 'l'))
        return true;
    if (a == 'j' && b == 'l')
        return true;
    if (a == 'l' && b == 'j')
        return true;
    if (a == 'v' && b == 'w')
        return true;
    
    return false;
}
int solve(int x, int y)
{
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    if (x == n && y == m) return ret = 0;
    ret = 1e9;
    if (x + 1 <= n && y + 1 <= m && equal(s[x], t[y]))
        ret = min(ret, solve(x + 1, y + 1));
    if (y + 1 <= m) ret = min(ret, solve(x, y + 1) + 1);
    if (x + 1 <= n) ret = min(ret, solve(x + 1, y) + 1);
    if (x + 1 <= n && y + 1 <= m) ret = min(ret, solve(x + 1, y + 1) + 1);
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dp.resize(n + 5, vector<int>(m + 5, -1));
    cin >> s >> t;
    cout << solve(0, 0);
}
