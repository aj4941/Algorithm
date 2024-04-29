#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool calc(int num)
{
    int cnt[12] = { 0 };
    while (num > 0)
    {
        if (cnt[num % 10])
            return false;
        cnt[num % 10]++;
        num /= 10;
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        int ans = 0;
        for (int i = n; i <= m; i++)
        {
            if (calc(i))
                ans++;
        }

        cout << ans << "\n";
    }
}