#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n), v;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) v.push_back(a[i] - a[i - 1]);

    ll ans = a.back() - a.front();
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < k - 1; i++) ans -= v[i];

    cout << ans;
}