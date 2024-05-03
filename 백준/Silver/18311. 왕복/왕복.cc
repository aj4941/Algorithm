#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> a(n), v1, v2;
    v1.push_back(0); v2.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v1.push_back(v1.back() + a[i]);
    }

    for (int i = n - 1; i >= 0; i--)
        v2.push_back(v2.back() + a[i]);

    if (k <= v1.back())
    {
        int idx = upper_bound(v1.begin(), v1.end(), k) - v1.begin();
        cout << idx;
        return 0;
    }

    k -= v1.back();

    int idx = upper_bound(v2.begin(), v2.end(), k) - v2.begin();
    cout << (n + 1) - idx;
}