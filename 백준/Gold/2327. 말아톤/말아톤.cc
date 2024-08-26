#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 100002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int dp[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int h, n; cin >> h >> n;
    vector<pii> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    dp[0] = 1e9;

    for (int i = 0; i < n; i++)
    {
        for (int H = h; H >= 0; H--)
        {
            if (H - a[i].first >= 0)
                dp[H] = max(dp[H], min(dp[H - a[i].first], a[i].second));
        }
    }

    cout << dp[h];
}