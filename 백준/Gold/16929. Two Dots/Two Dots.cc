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
const int N = 100;
string s[N];
int n, m;
bool cache[N][N];
bool hasAns = false;

void dfs(int x, int y, int px, int py)
{
    cache[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (s[x][y] != s[nx][ny] || (nx == px && ny == py)) continue;
        if (cache[nx][ny])
        {
            cout << "Yes";
            exit(0);
        }
        dfs(nx, ny, x, y);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (cache[i][j]) continue;
        dfs(i, j, -1, -1);
    }

    cout << "No";
}