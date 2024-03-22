#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
ll dp[17][1 << 17];
ll n, w[20][20];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) for (int bit = 0; bit < (1 << n); bit++)
        dp[i][bit] = 1e15;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> w[i][j];

    for (int i = 1; i < n; i++)
    {
        if (w[0][i] == 0) continue;
        dp[i][(1 << i)] = w[0][i];
    }

    for (int nbit = 1; nbit < (1 << n); nbit++)
    {
        for (int i = 0; i < n; i++) // j -> i
        {
            if ((nbit & (1 << i)) == 0) continue; // i 경로 포함
            for (int j = 0; j < n; j++)
            {
                if (w[j][i] == 0) continue;
                if ((nbit & (1 << j)) == 0) continue; // j 경로 포함
                int bit = nbit - (1 << i);
                dp[i][nbit] = min(dp[i][nbit], dp[j][bit] + w[j][i]);
            }
        }
    }

    cout << dp[0][(1 << n) - 1];
}