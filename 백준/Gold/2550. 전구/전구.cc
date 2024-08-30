#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 20002;
int a[N], b[N], c[N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> tmp, rtmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        c[b[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        tmp.push_back(c[a[i]]);
        rtmp.push_back(c[a[i]]);
    }

    reverse(rtmp.begin(), rtmp.end());

    vector<int> v, rv;
    vector<int> pos(n + 1), rpos(n + 1);

    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(v.begin(), v.end(), tmp[i]) - v.begin();
        if (idx == v.size())
        {
            v.push_back(tmp[i]);
            pos[i] = v.size();
        }
        else
        {
            v[idx] = tmp[i];
            pos[i] = idx + 1;
        }

        idx = lower_bound(rv.begin(), rv.end(), rtmp[i]) - rv.begin();
        if (idx == rv.size())
        {
            rv.push_back(rtmp[i]);
            rpos[i] = rv.size();
        }
        else
        {
            rv[idx] = rtmp[i];
            rpos[i] = idx + 1;
        }
    }

    vector<int> ans;
    
    int cnt = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (pos[i] == cnt)
        {
            ans.push_back(b[tmp[i]]);
            cnt--;
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";

    for (auto to : ans)
        cout << to << ' ';
}