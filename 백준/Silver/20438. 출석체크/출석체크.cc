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
int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 7002;
int n, k, q, m;
bool fail[N], cache[N];
int psum[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k >> q >> m;

    for (int i = 0; i < k; i++)
    {
        int x; cin >> x;
        fail[x] = true;
    }

    for (int i = 0; i < q; i++)
    {
        int x; cin >> x;
        if (fail[x] || cache[x]) continue;
        queue<int> q; q.push(x); cache[x] = true;
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            int cv = v;
            while (cv <= n + 2)
            {
                if (fail[cv] || cache[cv])
                {
                    cv += v;
                    continue;
                }
                q.push(cv); cache[cv] = true;
                cv += v;
            }
        }
    }

    for (int i = 3; i <= n + 2; i++)
    {
        if (!cache[i]) psum[i] = 1;
        psum[i] += psum[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        int s, e; cin >> s >> e;
        cout << psum[e] - psum[s - 1] << "\n";
    }
}