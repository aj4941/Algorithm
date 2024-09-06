#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 2000;
int a[N][N];
int n;

int solve(int x, int y, int sz)
{
    if (sz == 1)
        return a[x][y];
    int r1 = solve(x, y, sz / 2);
    int r2 = solve(x, y + sz / 2, sz / 2);
    int r3 = solve(x + sz / 2, y, sz / 2);
    int r4 = solve(x + sz / 2, y + sz / 2, sz / 2);
    vector<int> v = { r1, r2, r3, r4 };
    sort(v.begin(), v.end());
    return v[1];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    cout << solve(0, 0, n);
}