#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };
const int N = 200002;
int dp[N][9];
vector<pii> tmp;
int n;

int solve(int x, int y)
{
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 0;
    if (x == n)
    {
        if (y == 0) return ret = 1;
        else return ret = 0;
    }
    pii r1 = tmp[x * 2], r2 = tmp[x * 2 + 1];
    if (r1.first == 1)
        ret |= solve(x + 1, (y + r1.second) % 7);
    else
        ret |= solve(x + 1, (y * r1.second) % 7);

    if (r2.first == 1)
        ret |= solve(x + 1, (y + r2.second) % 7);
    else
        ret |= solve(x + 1, (y * r2.second) % 7);

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i <= n; i++) for (int j = 0; j <= 7; j++)
            dp[i][j] = -1;

        tmp.clear(), tmp.clear();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                char c; cin >> c;
                int x; cin >> x;
                if (c == '+') tmp.push_back({ 1, x });
                else tmp.push_back({ 2, x });
            }
        }

        if (solve(0, 1)) cout << "LUCKY" << "\n";
        else cout << "UNLUCKY" << "\n";
    }
}