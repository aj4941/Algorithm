#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B;
ll d1 = 100 - 1 + 1;
ll d2 = 10000 - 101 + 1;
ll d3 = 1000000 - 10001 + 1;

ll cost(ll w)
{
    ll res = 0;
    res += 2 * min(w, d1), w -= min(w, d1);
    res += 3 * min(w, d2), w -= min(w, d2);
    res += 5 * min(w, d3), w -= min(w, d3);
    res += 7 * w;
    return res;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true)
    {
        cin >> A >> B;
        if (A == 0 && B == 0) return 0;
        ll l = 0, r = 1e9;
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2 ;
            ll c = cost(mid);
            if (c < A) l = mid;
            else r = mid;
        }
        ll W = r;
        // cout << "W : " << W << endl;
        l = -1, r = W;
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            ll w1 = mid, w2 = W - w1;
            ll c1 = cost(w1), c2 = cost(w2);
            if (c2 - c1 > B) l = mid;
            else r = mid;
        }

        ll w1 = r;
        ll ans = cost(w1);

        cout << ans << "\n";
    }
}