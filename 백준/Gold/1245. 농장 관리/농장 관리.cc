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
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100;
int a[N][N];
int n, m;
bool cache[N][N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> a[i][j];

    ll ans = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (cache[i][j]) continue;
        queue<pii> q; q.push({ i, j }); cache[i][j] = true;
        bool flag = true;

        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int k = 0; k < 8; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (a[x][y] < a[nx][ny]) flag = false;
                if (cache[nx][ny]) continue;
                if (a[x][y] == a[nx][ny])
                {
                    q.push({ nx, ny });
                    cache[nx][ny] = true;
                }
            }
        }

        if (flag)
        {
            // cout << "pos : " << i << ' ' << j << endl;
            ans++;
        }
    }

    cout << ans;
}