#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
int a[50][50];

ll solve(int x1, int y1, int x2, int y2,  int p)
{
    ll res = 0;
    bool cutting = false;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (a[i][j] == 1)
            {
                bool flag = true;
                if (p == 0)
                {
                    for (int ni = x1; ni <= x2; ni++)
                    {
                        if (a[ni][j] == 2)
                            flag = false;
                    }
                    if (flag)
                    {
                        res += solve(x1, y1, x2, j - 1, 1 - p) *
                                solve(x1, j + 1, x2, y2, 1 - p);
                        cutting = true;
                    }
                }
                else
                {
                    for (int nj = y1; nj <= y2; nj++)
                    {
                        if (a[i][nj] == 2)
                            flag = false;
                    }
                    if (flag)
                    {
                        res += solve(x1, y1, i - 1, y2, 1 - p) *
                                solve(i + 1, y1, x2, y2, 1 - p);
                        cutting = true;
                    }
                }
            }
        }
    }

    if (!cutting)
    {
        bool hasAns = true;
        int cnt = 0;
        for (int i = x1; i <= x2; i++) for (int j = y1; j <= y2; j++)
        {
            if (a[i][j] == 1)
                hasAns = false;
            if (a[i][j] == 2)
                cnt++;
        }

        if (hasAns && cnt == 1)
            return 1;
        else
            return 0;
    }
    return res;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    ll ans1 = solve(0, 0, n - 1, n - 1, 0);
    ll ans2 = solve(0, 0, n - 1, n - 1, 1);
    ll ans = ans1 + ans2;
    if (ans == 0) ans = -1;
    cout << ans;
}