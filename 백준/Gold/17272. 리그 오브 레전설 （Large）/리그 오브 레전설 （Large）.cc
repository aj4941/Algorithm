#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> vll;
const int N = 1002;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const ll inf = 1000000007;
const int SIZE = 105;
ll n, m;
vll I(SIZE, vector<ll>(SIZE));
vll f(SIZE, vector<ll>(SIZE));
vll mid(SIZE, vector<ll>(SIZE));

vll mul(vll a, vll b)
{
    vll ret(m + 5, vector<ll>(m + 5));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                ret[i][j] += (a[i][k] * b[k][j]) % inf;
                ret[i][j] %= inf;
            }
        }
    }
    return ret;
}

vll mpow(vll a, ll x)
{
    if (x == 0) return I;
    vll tmp = mpow(a, x / 2);
    vll ret = mul(tmp, tmp);
    if (x % 2) ret = mul(ret, mid);
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n < m)
    {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        I[i][i] = 1;
        if (i < m) f[i][1] = 1;
        else f[i][1] = 2;
        if (i < m) mid[i][i + 1] = 1;
    }

    mid[m][m] = mid[m][1] = 1;

    vll ans = mpow(mid, n - m);
    ans = mul(ans, f);

    cout << ans[m][1];
}