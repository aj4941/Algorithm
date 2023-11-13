#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
int dp[7][7][7][7][7][7][7]; // num, 1, 2, 3, 4, 5, 6
int n, cnt[10];

int solve(int num, int v1, int v2, int v3, int v4, int v5, int v6)
{
    int &ret = dp[num][v1][v2][v3][v4][v5][v6];
    if (ret != -1) return ret;
    ret = (num == 4) ? 1 : 0;
    if (ret == 1) return ret;
    if (v1 + 1 <= cnt[1]) ret |= solve((num + 1) % 7, v1 + 1, v2, v3, v4, v5, v6);
    if (v2 + 1 <= cnt[2]) ret |= solve((num + 2) % 7, v1, v2 + 1, v3, v4, v5, v6);
    if (v3 + 1 <= cnt[3]) ret |= solve((num + 3) % 7, v1, v2, v3 + 1, v4, v5, v6);
    if (v4 + 1 <= cnt[4]) ret |= solve((num + 4) % 7, v1, v2, v3, v4 + 1, v5, v6);
    if (v5 + 1 <= cnt[5]) ret |= solve((num + 5) % 7, v1, v2, v3, v4, v5 + 1, v6);
    if (v6 + 1 <= cnt[6]) ret |= solve((num + 6) % 7, v1, v2, v3, v4, v5, v6 + 1);
    return ret;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    bool hasAns = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; x %= 7;
        cnt[x]++;
        if (x > 0 && cnt[x] >= 7)
            hasAns = true;
    }

    if (hasAns)
    {
        cout << "YES";
        return 0;
    }

    if (solve(0, 0, 0, 0, 0, 0, 0)) cout << "YES";
    else cout << "NO";
}