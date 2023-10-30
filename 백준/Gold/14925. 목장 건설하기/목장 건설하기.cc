#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
int n, m;
int a[N][N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
    {
        int x; cin >> x;
        a[i][j] = (x == 0) ? 1 : 0;
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        a[i][j] += a[i][j - 1];
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        a[i][j] += a[i - 1][j];

    int l = 0, r = 1e9;
    while (l + 1 < r) // [l, r)
    {
        int mid = (l + r) / 2;
        bool flag = false;
        for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        {
            if (i - mid < 0 || j - mid < 0) continue;
            int val = a[i][j] - a[i][j - mid] - a[i - mid][j] + a[i - mid][j - mid];
            if (val == mid * mid)
            {
                flag = true;
                break;
            }
        }
        if (flag) l = mid;
        else r = mid;
    }

    cout << l;
}