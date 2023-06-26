#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> v;
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        cin >> a[i];
    }

    int ans_cnt = 1e9, ans_bit = 0;

    for (int bit = 1; bit < (1 << n); bit++)
    {
        int res = 0, cnt = 0;
        vector<bool> cache(m);
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                cnt++;
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] == 'Y')
                        cache[j] = true;
                }
            }
        }

        int bit_cnt = 0;

        for (int i = 0; i < m; i++)
        {
            if (cache[i])
                bit_cnt++;
        }

        if (ans_bit < bit_cnt)
        {
            ans_bit = bit_cnt;
            ans_cnt = cnt;
        }
        else if (ans_bit == bit_cnt)
            ans_cnt = min(ans_cnt, cnt);
    }

    if (ans_cnt == 1e9 || ans_bit == 0) ans_cnt = -1;
    cout << ans_cnt;
}