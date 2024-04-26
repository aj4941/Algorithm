#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 200002;
int n, m, k;
int indegree[N];
vector<int> g[N];
int cnt[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); indegree[v]++;
    }

    bool hasAns = true;

    for (int i = 0; i < k; i++)
    {
        int c, x; cin >> c >> x;
        if (c == 1)
        {
            if (indegree[x] == 0)
            {
                if (cnt[x] == 0)
                {
                    for (int nx : g[x])
                        indegree[nx]--;
                }
            }
            else
            {
                hasAns = false;
                break;
            }
            cnt[x]++;
        }
        else
        {
            if (cnt[x] > 0)
            {
                cnt[x]--;
                if (cnt[x] == 0)
                {
                    for (int nx : g[x])
                        indegree[nx]++;
                }
            }
            else hasAns = false;
        }
    }

    if (hasAns) cout << "King-God-Emperor";
    else cout << "Lier!";
}