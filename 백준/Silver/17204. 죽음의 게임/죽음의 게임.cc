#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll inf = 1000000007;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int g[200];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int v; cin >> v;
        g[i] = v;
    }

    if (k == 0)
    {
        cout << 0;
        return 0;
    }

    int ans = 0, v = 0;
    while (ans < 200)
    {
        int nv = g[v]; ans++;
        if (nv == k)
        {
            cout << ans;
            return 0;
        }
        v = nv;
    }

    cout << -1;
}
