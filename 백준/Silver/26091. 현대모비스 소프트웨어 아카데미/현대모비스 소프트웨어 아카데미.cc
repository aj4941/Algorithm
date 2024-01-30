#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    int ans = 0;

    while (true)
    {
        if (a[l] + a[r] >= m)
        {
            ans++;
            l++; r--;
        }

        if (l >= r) break;

        while (l < n && a[l] + a[r] < m) l++;

        if (l >= r) break;
    }

    cout << ans;
}