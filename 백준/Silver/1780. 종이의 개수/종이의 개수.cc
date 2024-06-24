#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll x, ll y) {
    return ((y) ? gcd(y, x % y) : x);
}
const int N = 27 * 27 * 3 + 50;
int n, a[N][N];
int r1, r2, r3;

void solve(int x1, int y1, int x2, int y2)
{
    bool flag = true;
    for (int i = x1; i < x2; i++) for (int j = y1; j < y2; j++)
    {
        if (a[x1][y1] != a[i][j])
            flag = false;
    }

    if (flag)
    {
        if (a[x1][y1] == -1) r1++;
        if (a[x1][y1] == 0) r2++;
        if (a[x1][y1] == 1) r3++;
        return;
    }

    int sz = (x2 - x1) / 3;

    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    {
        int cx = x1 + sz * i, cy = y1 + sz * j;
        int ncx = cx + sz, ncy = cy + sz;
        solve(cx, cy, ncx, ncy);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    solve(0, 0, n, n);

    cout << r1 << '\n' << r2 << '\n' << r3;
}