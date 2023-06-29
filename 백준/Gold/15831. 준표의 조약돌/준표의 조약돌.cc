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
int dy[4] = { 0, -1, 0, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int n, b, w;
int bcnt, wcnt;
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> b >> w;
    cin >> s;
    s[0] == 'W' ? wcnt++ : bcnt++;

    int l = 0, r = 0;
    int ans = 0;

    while (true)
    {
        if (bcnt <= b && wcnt >= w)
        {
            ans = max(ans, r - l + 1); r++;
            if (r == n) break;
            if (s[r] == 'B') bcnt++;
            else wcnt++;
            continue;
        }

        if (bcnt > b)
        {
            if (s[l] == 'B') bcnt--;
            else wcnt--;
            l++;
        }
        else
        {
            r++;
            if (s[r] == 'B') bcnt++;
            else wcnt++;
            if (r == n)
                break;
        }
    }

    cout << ans;
}