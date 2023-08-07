#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<tuple<ll, ll, ll>> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, H_atk; cin >> n >> H_atk;

    for (int i = 0; i < n; i++)
    {
        ll t, a, h; cin >> t >> a >> h;
        v.push_back({ t, a, h });
    }

    ll l = 0, r = 1e18;
    while (l + 1 < r) // (l, r]
    {
        ll mid = (l + r) / 2;
        ll h = mid, atk = H_atk; // 체력, 공격력
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            ll ti = get<0>(v[i]), ai = get<1>(v[i]), hi = get<2>(v[i]);
            if (ti == 1)
            {
                ll hcnt = (hi + atk - 1) / atk;
                ll mcnt = (h + ai - 1) / ai;
                if (hcnt > mcnt)
                {
                    flag = false;
                    break;
                }
                else
                    h -= (hcnt - 1) * ai;
            }
            else // ti == 2
            {
                atk += ai;
                ll nh = h + hi;
                h = min(mid, nh);
            }
        }

        if (flag) r = mid;
        else l = mid;
    }

    cout << r;
}