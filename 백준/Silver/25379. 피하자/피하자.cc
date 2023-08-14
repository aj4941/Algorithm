#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> idx;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if (x % 2) idx.push_back(i);
    }

    int ans = 1e9;
    int tmp = 0, x = 1;
    for (int i = 0; i < idx.size(); i++)
        tmp += abs(idx[i] - x++);

    ans = min(ans, tmp);

    tmp = 0, x = n;
    for (int i = (int)idx.size() - 1; i >= 0; i--)
        tmp += abs(idx[i] - x--);

    ans = min(ans, tmp);

    if (ans == 1e9) ans = 0;

    cout << ans;
}