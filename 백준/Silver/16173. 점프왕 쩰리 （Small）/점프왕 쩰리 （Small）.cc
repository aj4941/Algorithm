#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int a[10][10];
int n;
bool hasAns = false;
bool cache[10][10];

void dfs(int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        hasAns = true;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i] * a[x][y], ny = y + dy[i] * a[x][y];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (cache[nx][ny]) continue;
        cache[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    cache[0][0] = true;
    dfs(0, 0);
    if (hasAns) cout << "HaruHaru";
    else cout << "Hing";
}