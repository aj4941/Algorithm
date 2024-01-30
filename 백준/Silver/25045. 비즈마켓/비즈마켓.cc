#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, m;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.rbegin(), a.rend()); sort(b.begin(), b.end());
    while (a.size() > b.size()) a.pop_back();
    while (b.size() > a.size()) b.pop_back();

    int n = a.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += max(0ll, a[i] - b[i]);

    cout << ans;
}
