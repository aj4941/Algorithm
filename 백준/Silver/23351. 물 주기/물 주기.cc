#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, a, b; cin >> n >> k >> a >> b;
    vector<int> v(n, k);
    int idx = 0, days = 1;
    while (true)
    {
        for (int i = idx; i < idx + a; i++) v[i] += b;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            v[i]--;
            if (v[i] <= 0)
            {
                flag = false;
                break;
            }
        }
        if (!flag) break;
        days++; idx = (idx + a) % n;
    }

    cout << days;
}