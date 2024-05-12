#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, -1, 1 };
const int N = 120;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<double> val(N);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x; cin >> x;
            double v; cin >> v;
            val[x] = max(val[x], v);
        }
    }

    sort(val.rbegin(), val.rend());
    double ans = 0;

    for (int i = 0; i < k; i++)
        ans += val[i];

    cout << fixed << setprecision(1) << ans;
}