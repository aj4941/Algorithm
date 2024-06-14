#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll dp[52][52][52][3][3];
ll A, B, C;

// 0 : not, 1 : 'A', 2 : 'B', 3 : 'C'
ll solve(int a, int b, int c, int r1, int r2)
{
    ll &ret = dp[a][b][c][r1][r2];
    if (ret != -1) return ret;
    if (a == A && b == B && c == C) return ret = 1;
    ret = 0;
    if (a + 1 <= A) ret |= solve(a + 1, b, c, r2, 1);
    if (b + 1 <= B && r2 != 2) ret |= solve(a, b + 1, c, r2, 2);
    if (c + 1 <= C && r1 != 3 && r2 != 3) ret |= solve(a, b, c + 1, r2, 3);
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    string s; cin >> s;
    for (auto to : s)
    {
        if (to == 'A') A++;
        if (to == 'B') B++;
        if (to == 'C') C++;
    }

    ll ans = solve(0, 0, 0, 0, 0);

    if (ans == 0)
    {
        cout << -1;
        return 0;
    }

    ll a = 0, b = 0, c = 0, r1 = 0, r2 = 0;

    while (a < A || b < B || c < C)
    {
        if (a + 1 <= A && dp[a + 1][b][c][r2][1] == 1)
        {
            a++, r1 = r2, r2 = 1;
            cout << 'A';
            continue;
        }
        if (b + 1 <= B && r2 != 2 && dp[a][b + 1][c][r2][2] == 1)
        {
            b++, r1 = r2, r2 = 2;
            cout << 'B';
            continue;
        }
        if (c + 1 <= C && r1 != 3 && r2 != 3 && dp[a][b][c + 1][r2][3] == 1)
        {
            c++, r1 = r2, r2 = 3;
            cout << 'C';
            continue;
        }
    }
}