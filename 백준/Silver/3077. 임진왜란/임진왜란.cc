#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
unordered_map<string, int> mp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        mp[s] = i + 1;
    }

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        v.push_back(mp[s]);
    }

    int ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] < v[j])
                ans++;
        }
    }

    cout << ans << "/" << (n * (n - 1) / 2);
}