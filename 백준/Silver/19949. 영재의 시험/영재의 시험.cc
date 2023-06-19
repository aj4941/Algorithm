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
const int N = 20;
vector<int> v;
int p[N];
ll ans = 0;

void dfs(int idx)
{
    if (idx == 10)
    {
        bool hasAns = true;
        for (int i = 0; i < 10 - 2; i++)
        {
            if (p[i] == p[i + 1] && p[i + 1] == p[i + 2])
                hasAns = false;
        }

        if (hasAns)
        {
            int pt = 0;
            for (int i = 0; i < 10; i++)
            {
                if (p[i] == v[i])
                    pt++;
            }

            if (pt >= 5)
                ans++;
        }
        return;
    }

    for (int x = 1; x <= 5; x++)
    {
        p[idx] = x;
        dfs(idx + 1);
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i < 10; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }

    dfs(0);
    cout << ans;
}