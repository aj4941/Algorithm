#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
ll gcd(ll x, ll y) {
    return ((y) ? gcd(y, x % y) : x);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(a.begin(), a.end());

    int ans = 1, mx = a[0];

    for (int i = 1; i < n; i++)
    {
        if (mx < a[i])
            ans++, mx = a[i];
    }

    cout << ans;
}