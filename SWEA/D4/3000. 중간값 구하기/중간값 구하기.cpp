#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const ll inf = 20171109;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        priority_queue<int> mn, mx;
        int n, a; cin >> n >> a;
        mn.push(a);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y; cin >> x >> y;
            mx.push(-x);
            int mn_val = mn.top(), mx_val = -mx.top();
            if (mn_val > mx_val)
            {
                mn.pop(); mx.pop();
                mn.push(mx_val); mx.push(-mn_val);
            }

            mn.push(y);
            mn_val = mn.top(), mx_val = -mx.top();
            if (mn_val > mx_val)
            {
                mn.pop(); mx.pop();
                mn.push(mx_val); mx.push(-mn_val);
            }

            ans += mn.top(); ans %= inf;
        }
        cout << "#" << tc << ' ' << ans << "\n";
    }
}