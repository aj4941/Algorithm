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
    int t; cin >> t;
    while (t--)
    {
        int x, y, z; cin >> x >> y >> z;
        int ans = 0;
        for (int i = 1; i <= x; i++) for (int j = 1; j <= y; j++) for (int k = 1; k <= z; k++)
        {
            int r1 = i % j, r2 = j % k, r3 = k % i;
            if (r1 == r2 && r2 == r3)
                ans++;
        }

        cout << ans << "\n";
    }
}