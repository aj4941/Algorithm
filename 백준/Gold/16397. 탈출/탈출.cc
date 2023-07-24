#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int MAX = 99999;
int cache[MAX + 5];

int calc(int x, int c)
{
    if (c == 1)
    {
        int res = x + 1;
        if (res > MAX) return -1;
        return res;
    }
    else
    {
        int res = x * 2;
        if (res > MAX) return -1;
        int mul = 1;
        while (res >= mul) mul *= 10;
        mul /= 10; res -= mul;
        return res;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, t, g; cin >> n >> t >> g;
    memset(cache, -1, sizeof cache);
    queue<int> q; q.push(n); cache[n] = 0;
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        int v1 = calc(v, 1), v2 = calc(v, 2);
        if (v1 != -1)
        {
            if (cache[v1] == -1)
            {
                q.push(v1);
                cache[v1] = cache[v] + 1;
            }
        }
        if (v2 != -1)
        {
            if (cache[v2] == -1)
            {
                q.push(v2);
                cache[v2] = cache[v] + 1;
            }
        }
    }

    int ans = cache[g];
    if (ans <= t && ans != -1) cout << ans;
    else cout << "ANG";
}