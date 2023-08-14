#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 100002;
int dp[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> v = { 2, 3 };
    while (v.back() < N)
        v.push_back(v[v.size() - 1] + v[v.size() - 2]);

    int n; cin >> n;
    if (n % 2 == 0) cout << n / 2;
    else cout << (n - 3) / 2 + 2;
    cout << ' ';

    for (int i = 1; i < N; i++) dp[i] = -1e9;
    for (int i = 2; i <= n; i++)
    {
        int idx = upper_bound(v.begin(), v.end(), i) - v.begin();
        for (int j = idx - 1; j >= 0; j--)
        {
            if (dp[i - v[j]] == 1e9) continue;
            if (j > 0) dp[i] = max(dp[i], dp[i - v[j]] + v[j - 1]);
            else dp[i] = max(dp[i], dp[i - v[j]] + 1);
        }
    }

    cout << dp[n];
}