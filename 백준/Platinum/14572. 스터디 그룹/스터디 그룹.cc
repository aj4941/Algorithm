#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 100005;
vector<pll> v;
ll cnt[50];
ll or_cnt = 0, and_cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k, D; cin >> n >> k >> D;
    for (int i = 0; i < n; i++)
    {
        ll m, d; cin >> m >> d;
        ll bit = 0;
        for (int j = 0; j < m; j++)
        {
            ll x; cin >> x;
            bit |= (1 << x);
        }
        v.push_back({ d, bit });
    }

    sort(v.begin(), v.end());

    ll l = 0, r = 0;

    for (int i = 1; i <= 30; i++)
    {
        if (v[0].second & (1ll << i))
            cnt[i]++, or_cnt++, and_cnt++;
    }

    ll ans = (or_cnt - and_cnt) * 1;

    while (r < n)
    {
        if (r + 1 < n && v[r + 1].first - v[l].first <= D)
        {
            for (int i = 1; i <= 30; i++)
            {
                if (v[r + 1].second & (1ll << i))
                {
                    cnt[i]++;
                    if (cnt[i] == 1)
                        or_cnt++;
                }
                else if (cnt[i] == r - l + 1)
                    and_cnt--;
            }
            r++;
        }
        else
        {
            if (l + 1 > r)
            {
                for (int i = 1; i <= 30; i++) cnt[i] = 0;
                or_cnt = and_cnt = 0;
            }
            else
            {
                for (int i = 1; i <= 30; i++)
                {
                    if (v[l].second & (1ll << i))
                    {
                        cnt[i]--;
                        if (cnt[i] == 0)
                        {
                            or_cnt--;
                            if (r - l + 1 == 1)
                                and_cnt--;
                        }
                    }
                    else if (cnt[i] == (r - l + 1) - 1)
                        and_cnt++;
                }
            }
            l++;
            if (l > r)
            {
                r = l;
                if (r < n)
                {
                    for (int i = 1; i <= 30; i++)
                    {
                        if (v[r].second & (1ll << i))
                            cnt[i]++, or_cnt++, and_cnt++;
                    }
                }
            }
        }

        ans = max(ans, (or_cnt - and_cnt) * (r - l + 1));
    }

    cout << ans;
}