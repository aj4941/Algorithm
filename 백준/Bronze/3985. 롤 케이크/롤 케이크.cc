#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
typedef tuple<ll, ll, ll> tll;
int cnt1[2000], cnt2[2000];

int main(void)
{
    int l, n; cin >> l >> n;
    vector<int> a(l + 1);
    for (int i = 1; i <= n; i++)
    {
        int lv, rv; cin >> lv >> rv;
        cnt1[i] = rv - lv + 1;
        for (int j = lv; j <= rv; j++)
        {
            if (a[j] == 0)
            {
                a[j] = i;
                cnt2[i]++;
            }
        }
    }

    int mx1 = 0, mx2 = 0, ans1 = -1, ans2 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mx1 < cnt1[i])
        {
            mx1 = cnt1[i];
            ans1 = i;
        }
        if (mx2 < cnt2[i])
        {
            mx2 = cnt2[i];
            ans2 = i;
        }
    }

    cout << ans1 << "\n" << ans2;
}