#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
#define INF 1e18
vector<int> p;

int find(int v)
{
    if (p[v] == v) return v;
    else return p[v] = find(p[v]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    p.resize(n + 1);
    for (int i = 0; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, a, b; cin >> x >> a >> b;
        if (x == 0)
        {
            a = find(a); b = find(b);
            if (a != b) p[a] = b;
        }
        else
        {
            if (find(a) == find(b)) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}