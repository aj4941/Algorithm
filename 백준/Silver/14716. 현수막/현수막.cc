#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 300;
int a[N][N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> a[i][j];

    queue<pii> q;
    ll ans = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (a[i][j] == 1)
        {
            q.push({ i, j }); a[i][j] = -1; ans++;
            while (!q.empty())
            {
                int x = q.front().first, y = q.front().second; q.pop();
                for (int k = 0; k < 8; k++)
                {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (a[nx][ny] != 1) continue;
                    q.push({ nx, ny }); a[nx][ny] = -1;
                }
            }
        }
    }

    cout << ans;
}