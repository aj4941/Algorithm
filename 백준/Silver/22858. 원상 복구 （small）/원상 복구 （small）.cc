#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), d(n + 1), p(n + 1), np(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) p[i] = i;

    for (int t = 0; t < k; t++)
    {
        for (int i = 1; i <= n; i++)
            np[i] = p[d[i]];
        for (int i = 1; i <= n; i++)
            p[i] = np[i];
    }

    for (int i = 1; i <= n; i++)
        ans[p[i]] = a[i];

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}