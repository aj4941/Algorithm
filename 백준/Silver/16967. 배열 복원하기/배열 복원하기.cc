#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll N = 700;
ll a[N][N], b[N][N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll h, w, x, y; cin >> h >> w >> x >> y;
    for (ll i = 0; i < h + x; i++) for (ll j = 0; j < w + y; j++)
        cin >> b[i][j];

    for (ll i = 0; i < h + x; i++) for (ll j = 0; j < w + y; j++)
    {
        if (x <= i && i < h && y <= j && j < w)
            a[i][j] = b[i][j] - a[i - x][j - y];
        else if (i < h && j < w)
            a[i][j] = b[i][j];
    }

    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
            cout << a[i][j] << ' ';
        cout << "\n";
    }
}