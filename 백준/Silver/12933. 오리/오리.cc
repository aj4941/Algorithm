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
char ch[5] = { 'q', 'u', 'a', 'c', 'k' };
const int N = 2502;
bool cache[N];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s; cin >> s;
    int ans = 0;

    for (int t = 0; t < 3000; t++)
    {
        int idx = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (cache[i]) continue;
            if (ch[idx] == s[i])
            {
                cnt++;
                idx = (idx + 1) % 5;
                cache[i] = true;
            }
        }

        if (cnt % 5 == 0)
        {
            if (cnt > 0)
                ans++;
        }
        else
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (!cache[i])
        {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}