#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < (n - 1) / 2; i++) ans -= a[i];

    reverse(a.begin(), a.end());
    for (int i = 0; i < (n + 1) / 2; i++) ans += a[i];

    cout << ans;
}