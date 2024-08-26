#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 5002;
bool dp[N][1002];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    
    while (t--)
    {
        int n, m; cin >> n >> m;
        vector<int> s(m);
        for (int i = 0; i < m; i++) cin >> s[i];
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        int ans = -1;

        for (int x = 1; x <= n; x++) for (int y = 1; y <= min(x, 1000); y++)
        {
            int k = x - y;
            for (int i = 0; i < m; i++)
            {
                if (y - s[i] >= 0 && dp[k][y - s[i]] == true)
                {
                    dp[x][y] = true;
                    if (x == n) ans = max(ans, y);
                }
            }
        }

        cout << ans << "\n";
    }
}