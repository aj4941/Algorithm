#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int INF = 1001;
const int MAX = 1001 * 1000 + 5000; // [1000, 1000] == 1001 * 1000 + 1000
vector<tuple<int, int, int, int>> vec;
int p[MAX];
bool cache[1002][1002];

int find(int x)
{
    if (p[x] == x) return x;
    else return p[x] = find(p[x]);
}

int pos(int x, int y)
{
    return x * INF + y;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i < MAX; i++) p[i] = i;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        vec.push_back({ x1 + 500, y1 + 500, x2 + 500, y2 + 500 }); // [0, 1000]
    }

    vec.push_back({ 500, 500, 500, 500 });
    cache[500][500] = true;
    
    for (int i = 0; i < (int)vec.size(); i++)
    {
        int x1 = get<0>(vec[i]), y1 = get<1>(vec[i]), x2 = get<2>(vec[i]), y2 = get<3>(vec[i]);
        int v = find(pos(x1, y1));
        for (int y = y1; y <= y2; y++)
        {
            int u = find(pos(x1, y)); cache[x1][y] = true;
            p[u] = v;
        }
        for (int x = x1; x <= x2; x++)
        {
            int u = find(pos(x, y2)); cache[x][y2] = true;
            p[u] = v;
        }
        for (int y = y2; y >= y1; y--)
        {
            int u = find(pos(x2, y)); cache[x2][y] = true;
            p[u] = v;
        }
        for (int x = x2; x >= x1; x--)
        {
            int u = find(pos(x, y1)); cache[x][y1] = true;
            p[u] = v;
        }
    }

    ll ans = 0;

    for (int i = 0; i <= 1000; i++) for (int j = 0; j <= 1000; j++)
    {
        if (cache[i][j] && find(pos(i, j)) == pos(i, j))
            ans++;
    }

    cout << ans - 1;
}