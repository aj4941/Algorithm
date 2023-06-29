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
int dy[4] = { 0, -1, 0, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 200;
string s[N];
int n, m;
bool cache[N][N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];

    queue<pii> q; q.push({ n - 1, m - 1 });
    cache[n - 1][m - 1] = true;
    int ans = 0;

    while (!q.empty())
    {
        auto to = q.front(); q.pop();
        int x = to.first, y = to.second;
        if (s[x][y] == '1')
        {
            ans++;
            for (int i = 0; i <= x; i++) for (int j = 0; j <= y; j++)
                s[i][j] = '0' + '1' - s[i][j];
        }

        for (int k = 0; k < 2; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0) continue;
            if (cache[nx][ny]) continue;
            q.push({ nx, ny });
            cache[nx][ny] = true;
        }
    }

    cout << ans;
}