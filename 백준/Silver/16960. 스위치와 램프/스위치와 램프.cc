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
vector<vector<int>> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        v.push_back({});
        int l; cin >> l;
        for (int j = 0; j < l; j++)
        {
            int x; cin >> x;
            v.back().push_back(x);
        }
    }

    bool hasAns = false;

    for (int k = 0; k < n; k++)
    {
        vector<bool> cache(m + 1, false);
        for (int i = 0; i < n; i++)
        {
            if (i == k) continue;
            for (auto to : v[i])
                cache[to] = true;
        }

        bool flag = true;

        for (int i = 1; i <= m; i++)
        {
            if (!cache[i])
                flag = false;
        }

        if (flag)
            hasAns = true;
    }

    if (hasAns) cout << 1;
    else cout << 0;
}