#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
typedef tuple<ll, ll, ll> tll;

int main(void)
{
    int n, k, d; cin >> n >> k >> d;
    vector<tll> v;
    for (int i = 0; i < k; i++)
    {
        ll a, b, c; cin >> a >> b >> c;
        v.push_back({ a, b, c });
    }

    ll l = 0, r = 1e18;
    while (l + 1 < r) // (l, r]
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < k; i++)
        {
            ll st = get<0>(v[i]), ed = min(get<1>(v[i]), mid), c = get<2>(v[i]);
            if (st > ed) continue;
            cnt += (ed - st) / c + 1;
        }
            if (cnt >= d) r = mid;
            else l = mid;
    }

    cout << r;
}