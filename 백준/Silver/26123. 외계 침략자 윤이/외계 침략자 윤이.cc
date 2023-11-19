#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005;
int cnt[N], mx;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, D; cin >> n >> D;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mx = max(mx, x); cnt[x]++;
    }

    ll ans = 0;

    while (D > 0 && mx > 0)
    {
        ans += cnt[mx];
        cnt[mx - 1] += cnt[mx]; mx--;
        D--;
    }

    cout << ans;
}