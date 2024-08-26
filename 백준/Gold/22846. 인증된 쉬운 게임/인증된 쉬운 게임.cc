#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 100002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n;
int dp[N];

int solve(int x)
{
    int &ret = dp[x];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i != 0) continue;
        int v1 = x / i, v2 = x / (x / i);
        if (x + v1 <= n && solve(x + v1) == 0)
        {
            ret = 1;
            break;
        }
        if (x + v2 <= n && solve(x + v2) == 0)
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;

    if (solve(1)) cout << "Kali";
    else cout << "Ringo";
}