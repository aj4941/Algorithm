#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
int cache[100002];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];

    int ans = 0, cnt = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        if (cache[a[i]] == 0)
        {
            cnt++;
            cache[a[i]] = 1;
        }
        else
        {
            cache[a[i]] = 0;
            cnt--;
        }

        ans = max(ans, cnt);
    }

    cout << ans;
}