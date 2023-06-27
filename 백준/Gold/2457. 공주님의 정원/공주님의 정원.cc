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
int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int n;
pii p[20][40];

pii calc(pii a, pii b)
{
    if (a.first > b.first) return a;
    else if (b.first > a.first) return b;
    else if (a.second > b.second) return a;
    else return b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 12; i++) for (int j = 1; j <= 31; j++) p[i][j] = pii(0, 0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int sm, sd, em, ed; cin >> sm >> sd >> em >> ed;
        p[sm][sd] = calc(p[sm][sd], pii(em, ed));
    }

    int m = 1, d = 1;

    while (true)
    {
        int nm = m, nd = d + 1;
        if (nd > month[nm])
        {
            nm = m + 1;
            nd = 1;
        }
        if (nm == 13) break;
        p[nm][nd] = calc(p[m][d], p[nm][nd]);
        m = nm, d = nd;
    }

    m = 3, d = 1;
    int ans = 0;
    bool hasAns = true;

    while (true)
    {
        ans++;
        pii nxt = p[m][d];

        if (calc(pii(m, d), nxt) == pii(m, d))
        {
            hasAns = false;
            break;
        }

        m = nxt.first, d = nxt.second;
        if (m > 11) break;
    }

    if (!hasAns) ans = 0;
    cout << ans;
}