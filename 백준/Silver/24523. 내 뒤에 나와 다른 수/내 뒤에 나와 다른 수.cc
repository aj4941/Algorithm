#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };
const int N = 1000002;
int dp[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ans[n] = -1;

    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] == a[i + 1])
            ans[i] = ans[i + 1];
        else
            ans[i] = i + 1;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}