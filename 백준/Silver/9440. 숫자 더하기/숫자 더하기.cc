#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
int a[N], n;
bool cache[N];
ll ans = 1e18;

void Swap(vector<int> &v)
{
    if (v.size() == 0) return;
    if (v[0] == 0)
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] != 0)
            {
                swap(v[i], v[0]);
                break;
            }
        }
    }
    return;
}

void dfs(int idx)
{
    if (idx == n)
    {
        vector<int> v1, v2;
        for (int i = 0; i < n; i++)
        {
            if (cache[i]) v1.push_back(a[i]);
            else v2.push_back(a[i]);
        }

        if (v1.size() == 0 || v2.size() == 0) return;

        sort(v1.begin(), v1.end()); Swap(v1);
        sort(v2.begin(), v2.end()); Swap(v2);

        if (v1[0] == 0 && v1.size() >= 2) return;
        if (v2[0] == 0 && v2.size() >= 2) return;

        ll val1 = 0, val2 = 0;

        for (auto to : v1) val1 = val1 * 10 + to;
        for (auto to : v2) val2 = val2 * 10 + to;
        ans = min(ans, val1 + val2);
        return;
    }
    dfs(idx + 1);
    cache[idx] = true;
    dfs(idx + 1);
    cache[idx] = false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true)
    {
        ans = 1e18; cin >> n;
        if (n == 0) return 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        dfs(0); cout << ans << "\n";
    }
}