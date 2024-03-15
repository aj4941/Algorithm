#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 200002;
ll a[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> v;
    ll cnt = 1;

    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1]) cnt++;
        else
        {
            v.push_back(cnt);
            cnt = 1;
        }
    }

    v.push_back(cnt);

    ll ans = 0;

    if (v.size() == 1)
    {
        cout << v[0];
        return 0;
    }

    if (v.size() == 2)
    {
        cout << v[0] + v[1];
        return 0;
    }

    for (int i = 1; i < (int)v.size() - 1; i++)
        ans = max(ans, v[i - 1] + v[i] + v[i + 1]);

    cout << ans;
}