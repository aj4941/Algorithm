#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200;
bool cache[N];
ll dp[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        cache[x] = true;
    }

    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        if (!cache[i])
            v.push_back(i);
    }

    if (v.size() == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < v.size(); i++) dp[i] = 1e15;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j >= 0; j--)
        {
            ll dpValue = (j == 0) ? 0 : dp[j - 1];
            ll len = v[i] - v[j] + 1;
            dp[i] = min(dp[i], 5 + 2 * len + dpValue);
        }
    }

    cout << dp[(ll)v.size() - 1];
}