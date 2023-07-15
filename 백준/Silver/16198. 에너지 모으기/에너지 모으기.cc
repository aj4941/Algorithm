#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll ans = 0;

void dfs(ll val, vector<int>& a)
{
    if (a.size() == 2)
    {
        ans = max(ans, val);
        return;
    }

    int sz = a.size();

    for (int i = 1; i < sz - 1; i++)
    {
        vector<int> na;
        ll tmp = a[i - 1] * a[i + 1];
        for (int j = 0; j < sz; j++)
        {
            if (i == j) continue;
            na.push_back(a[j]);
        }
        dfs(val + tmp, na);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    dfs(0, a);

    cout << ans;
}