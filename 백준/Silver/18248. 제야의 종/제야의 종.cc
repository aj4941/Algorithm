#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1002;
int a[N][N];
int p[N][N], indegree[N];
vector<int> g[N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> a[i][j];

//    if (n == 1)
//    {
//        cout << "YES";
//        return 0;
//    }

    for (int j = 0; j < m; j++)
    {
        for (int x = 0; x < n; x++) for (int y = x + 1; y < n; y++)
        {
            if (a[x][j] == 1 && a[y][j] == 0) // x < y
                p[x][y] = 1;
            if (a[x][j] == 0 && a[y][j] == 1) // y < x
                p[y][x] = 1;
        }
    }

    for (int x = 0; x < n; x++) for (int y = 0; y < n; y++)
    {
        if (p[x][y])
        {
            g[x].push_back(y);
            indegree[y]++;
        }
    }

    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        cnt++;
        for (int nv : g[v])
        {
            indegree[nv]--;
            if (indegree[nv] == 0)
                q.push(nv);
        }
    }

    // cout << "cnt : " << cnt << endl;

    if (cnt == n)
        cout << "YES";
    else
        cout << "NO";
}
