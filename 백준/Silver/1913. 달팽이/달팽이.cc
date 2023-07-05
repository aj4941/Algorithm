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
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 2000;
int a[N][N];
pii pos[N * N];
int n, v, x, y, k;
int val = 1, len = 1, limit = 1;
bool flag = true;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> v;
    x = (n + 1) / 2, y = (n + 1) / 2;
    a[x][y] = val; pos[val] = pii(x, y);

    while (true)
    {
        int nx = x + dx[k], ny = y + dy[k]; val++; len--;
        a[nx][ny] = val; pos[val] = pii(nx, ny); x = nx, y = ny;
        if (len == 0)
        {
            k = (k + 1) % 4;
            if (k == 0 || k == 2) limit++;
            len = limit;
        }

        if (val == n * n) break;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << "\n";
    }

    cout << pos[v].first << ' ' << pos[v].second;
}