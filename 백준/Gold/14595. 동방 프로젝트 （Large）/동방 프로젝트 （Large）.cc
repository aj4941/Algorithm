#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
const int N = 2000002;
int n, m;
int p[N];

int find(int x)
{
    if (p[x] == x)
        return x;
    else
        return p[x] = find(p[x]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        for (int j = x; j < y; j++)
        {
            int u = find(j), v = find(j + 1);
            if (u != v)
                p[u] = v;
            
            j = v - 1;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            ans++;
    }

    cout << ans;
}