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
ll a[N], b[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        int l, r, c; cin >> l >> r >> c;
        b[l] += c, b[r + 1] -= c;
    }

    for (int i = 1; i < N; i++) b[i] += b[i - 1];

    for (int i = 1; i < N; i++) a[i] += b[i];

    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
}