#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // index 증가 -> 사전순으로 앞설 가능성 감소
    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        string s; cin >> s;
        int l = -1, r = n - 1;
        int len = s.size();
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (v[mid] < s) l = mid;
            else r = mid;
        }

        if (v[r].size() < s.size()) continue;
        if (v[r].substr(0, len) == s) ans++;
    }

    cout << ans;
}