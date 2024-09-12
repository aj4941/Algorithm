#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<pii> tmp; tmp.push_back({ n, a[n] });
    vector<int> ans = { -1 };

    for (int i = n - 1; i >= 1; i--)
    {
        int idx = 1e9;

        for (auto to : tmp)
        {
            if (to.second != a[i])
                idx = min(idx, to.first);
        }

        if (idx == 1e9) idx = -1;
        ans.push_back(idx);

        tmp.push_back({ i, a[i] });
        int sz = tmp.size();

        bool flag = true;
        
        for (int x = 0; x < sz && flag; x++) for (int y = x + 1; y < sz && flag; y++)
        {
            if (tmp[x].second == tmp[y].second)
            {
                tmp.erase(tmp.begin() + x);
                flag = false;
                break;
            }
        }

        if (tmp.size() == 3)
            tmp.erase(tmp.begin());
    }

    reverse(ans.begin(), ans.end());

    for (auto to : ans)
        cout << to << ' ';
}