#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 1e18;

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
    {
        ll asum = a[i] + a[j];
        ll l = 0, r = n - 1;
        while (true)
        {
            if (l == i || l == j) l++;
            else if (r == i || r == j) r--;
            else
            {
                ll bsum = a[l] + a[r];
                ans = min(ans, abs(asum - bsum));
                if (asum <= bsum) r--;
                else l++;
            }

            if (l >= r)
                break;
        }
    }

    cout << ans;
}
