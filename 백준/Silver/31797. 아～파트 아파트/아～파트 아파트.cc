#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const int N = 20002;
int cache[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    if (n >= 2 * m) n %= (2 * m);
    if (n == 0) n = 2 * m;
    for (int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        cache[x] = cache[y] = i;
    }

    int r = 0;

    for (int i = 1; i <= 10000; i++)
    {
        if (cache[i] != 0)
            r++;

        if (r == n)
        {
            cout << cache[i];
            return 0;
        }
    }
}