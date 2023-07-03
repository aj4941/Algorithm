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
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100;
int n;
int a[N][N];
bool cache[N][N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> a[i][j];

    queue<pii> q; q.push({ 0, 0 });
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second; q.pop();
        cache[x][y] = true;
        for (int k = 0; k < 2; k++)
        {
            int nx = x + dx[k] * a[x][y], ny = y + dy[k] * a[x][y];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (cache[nx][ny]) continue;
            q.push({ nx, ny }); cache[nx][ny] = true;
        }
    }

    if (cache[n - 1][n - 1]) cout << "HaruHaru";
    else cout << "Hing";
}