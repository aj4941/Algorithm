#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool cmp(pii &a, pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;

    return a.first < b.first;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), cmp);

    int t = 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        t += a[i].first;
        ans = min(ans, a[i].second - t);
    }

    cout << ans;
}