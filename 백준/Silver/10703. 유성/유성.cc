#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 3500;
int dist[N][N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int mn = 1e9;
    memset(dist, -1, sizeof dist);
    queue<pii> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (s[i][j] == '#')
        {
            dist[i][j] = 0;
            q.push({ i, j });
        }
    }

    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        if (s[x][y] == 'X') mn = min(mn, dist[x][y]);

        int nx = x - 1, ny = y;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (dist[nx][ny] != -1) continue;
        dist[nx][ny] = dist[x][y] + 1;
        q.push({ nx, ny });
    }

    for (int i = n - 1; i >= 0; i--) for (int j = 0; j < m; j++)
    {
        if (s[i][j] == 'X')
        {
            s[i + mn - 1][j] = 'X';
            s[i][j] = '.';
        }
    }

    // cout << endl;

    for (int i = 0; i < n; i++)
        cout << s[i] << "\n";
}