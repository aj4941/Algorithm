#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { 0, 1, 0, 0 };
int dy[4] = { 1, 0, -1, 1 };
const int N = 102;
int n, m;
int a[N][N];
bool cache[N * N];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<pii> v;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        cin >> a[i][j];
        if (a[i][j] == 1)
            v.push_back({ i, j });
    }

    sort(v.begin(), v.end());
    int sz = v.size();
    int ans = 0;

    for (int i = 0; i < sz; i++)
    {
        if (cache[i]) continue;
        ans++; cache[i] = true;
        int x = v[i].first, y = v[i].second;
        for (int j = i + 1; j < sz; j++)
        {
            if (cache[j]) continue;
            int nx = v[j].first, ny = v[j].second;
            if (x <= nx && y <= ny)
            {
                cache[j] = true;
                x = nx, y = ny;
            }
        }
    }

    cout << ans;
}