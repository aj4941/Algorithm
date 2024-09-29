#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 1002;
bool cache[N][N];
int n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) for (int y = y1; y < y2; y++)
            cache[x][y] = true;
    }

    int ans = 0;

    for (int x = 0; x < N; x++) for (int y = 0; y < N; y++)
    {
        if (cache[x][y])
            ans++;
    }

    cout << ans;
}