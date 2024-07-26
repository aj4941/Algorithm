#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 1002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cache[52][52], check[52][52];
int a[52][52], b[52][52];
vector<pii> v;
int n, m, g, r;
int ans;

void dfs2(int idx, int cnt, int c)
{
    if (cnt == r)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                b[i][j] = a[i][j];
        }

        queue<pii> q1, q2;

        for (auto to : v)
        {
            int x = to.first, y = to.second;
            if (cache[x][y] == 0) continue;
            b[x][y] = cache[x][y]; q1.push({ x, y });
        }

        memset(check, 0, sizeof check);
        int res = 0;

        while (true)
        {
            while (!q1.empty())
            {
                auto to = q1.front(); q1.pop();
                int x = to.first, y = to.second;
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (b[nx][ny] == 0 || b[nx][ny] == 3 || b[nx][ny] == 4 || b[nx][ny] == 5) continue;
                    if (check[nx][ny] == 0)
                    {
                        q2.push({ nx, ny });
                        check[nx][ny] = b[x][y];
                    }
                    else if (check[nx][ny] != b[x][y])
                        check[nx][ny] = 5;
                }
            }

            if (q2.size() == 0)
                break;

            while (!q2.empty())
            {
                auto to = q2.front(); q2.pop();
                int x = to.first, y = to.second;
                b[x][y] = check[x][y];
                if (b[x][y] == 5) res++;
                else q1.push({ x, y });
            }
        }

        ans = max(ans, res);
        return;
    }

    for (int i = idx; i < v.size(); i++)
    {
        int x = v[i].first, y = v[i].second;
        if (cache[x][y] > 0) continue;
        cache[x][y] = c;
        dfs2(i + 1, cnt + 1, c);
        cache[x][y] = 0;
    }
}

void dfs(int idx, int cnt, int c) // g = 3, r = 4
{
    if (cnt == g)
    {
        dfs2(0, 0, 4);
        return;
    }
    
    for (int i = idx; i < v.size(); i++)
    {
        int x = v[i].first, y = v[i].second;
        if (cache[x][y] > 0) continue;
        cache[x][y] = c;
        dfs(i + 1, cnt + 1, c);
        cache[x][y] = 0;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        cin >> a[i][j];
        if (a[i][j] == 2)
            v.push_back({ i, j });
    }

    dfs(0, 0, 3);

    cout << ans;
}