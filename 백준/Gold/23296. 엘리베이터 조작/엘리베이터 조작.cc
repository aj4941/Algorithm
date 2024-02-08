#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100002;
int g[N], indegree[N];
bool cache[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        g[i] = x; indegree[x]++;
    }

    deque<int> dq; dq.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        if (indegree[i] == 0)
            dq.push_back(i);
    }

    vector<int> ans;

    while (!dq.empty())
    {
        int v = dq.front(); dq.pop_front();
        ans.push_back(v); cache[v] = true;
        int nv = g[v]; g[v] = -1;
        if (nv == -1) continue;
        dq.push_front(nv);
    }

    for (int i = 2; i <= n; i++)
    {
        if (!cache[i])
        {
            int v = i;
            do {
                ans.push_back(v); cache[v] = true;
                int nv = g[v]; g[v] = -1;
                v = nv;
            } while (v != -1);
        }
    }

    cout << ans.size() - 1 << "\n";
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << ' ';
}