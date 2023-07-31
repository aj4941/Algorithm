#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    int ans = 0;
    int l = 1, r = m;
    for (int i = 0; i < k; i++)
    {
        if (l <= a[i] && a[i] <= r) continue;
        if (a[i] < l)
        {
            int rm = l - a[i];
            ans += rm; l -= rm; r -= rm;
        }
        else if (r < a[i])
        {
            int rm = a[i] - r;
            ans += rm; l += rm; r += rm;
        }
    }
    cout << ans;
}