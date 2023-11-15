#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1002;
int dp[N][10], a[N];
int n;

void solve(int i, int j)
{
    int &ret = dp[i][j];
    if (ret != -1) return;
    ret = 1;
    if (i == n) return;
    solve(i + 1, j);
    solve(i + 1, (j + a[i]) % 7);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= 7;
    }

    solve(0, 0);

    if (dp[n][4] == 1) cout << "YES";
    else cout << "NO";
}