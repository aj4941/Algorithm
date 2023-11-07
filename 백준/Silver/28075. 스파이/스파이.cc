#include <bits/stdc++.h>
using namespace std;
int dp[10][30][5][5];
int a[2][3];
int n, m;

int solve(int N, int M, int x, int y)
{
    if (N == 0)
    {
        if (M > 0) return 0;
        else return 1;
    }
    int &ret = dp[N][M][x][y];
    if (ret != -1) return ret;
    ret = 0;
    for (int nx = 0; nx < 2; nx++) for (int ny = 0; ny < 3; ny++)
    {
        if (y == ny) ret += solve(N - 1, max(0, M - a[nx][ny] / 2), nx, ny);
        else ret += solve(N - 1, max(0, M - a[nx][ny]), nx, ny);
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++)
        cin >> a[i][j];

    int ans = 0;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++)
        ans += solve(n - 1, max(0, m - a[i][j]), i, j);

    cout << ans;
}