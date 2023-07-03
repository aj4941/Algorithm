#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n;
int a[12][12];
pii prv[4];
int cache[12][12];
int ans = 1e9;

void dfs(int x, int y, int cnt)
{
    if (cnt == 3)
    {
        bool flag = true;
        int res = 0;
        vector<pii> tmp;
        for (int i = 0; i < 3; i++)
        {
            int x = prv[i].first, y = prv[i].second;
            res += a[x][y]; cache[x][y]++;
            tmp.push_back({ x, y });
            if (cache[x][y] > 1) flag = false;
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                {
                    flag = false;
                    continue;
                }
                cache[nx][ny]++; res += a[nx][ny];
                tmp.push_back({ nx, ny });
                if (cache[nx][ny] > 1)
                    flag = false;
            }
        }

        while (tmp.size())
        {
            int x = tmp.back().first, y = tmp.back().second;
            tmp.pop_back(); cache[x][y]--;
        }

        if (flag)
            ans = min(ans, res);

        return;
    }

    if (x == n)
        return;

    while (x < n)
    {
        prv[cnt] = pii(x, y); y++;
        if (y == n)
        {
            x = x + 1;
            y = 0;
        }
        dfs(x, y, cnt + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    dfs(0, 0, 0);
    cout << ans;
}