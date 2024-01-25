#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 2000002;
bool cache[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        for (int j = x; j <= c; j += x)
            cache[j] = true;
    }

    int ans = 0;

    for (int i = 1; i <= c; i++)
    {
        if (cache[i])
            ans++;
    }

    cout << ans;
}
