#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<pll> res;
const ll MAX = LLONG_MAX - 1;
ll mn_x = MAX, mx_x = -MAX, mn_y = MAX, mx_y = -MAX;

void calc(vector<int> &v1, vector<int> &v2)
{
    ll A = v1[0], B = v1[1], E = v1[2];
    ll C = v2[0], D = v2[1], F = v2[2];
    ll p = A * D - B * C, a = B * F - E * D, b = E * C - A * F;
    // cout << "p : " << p << ' ' << a << ' ' << b << endl;
    if (p == 0) return;
    if (abs(a) % abs(p) || abs(b) % abs(p)) return;
    ll x = abs(a) / abs(p);
    ll y = -(abs(b) / abs(p));
    if (a * p < 0) x = -x;
    if (b * p < 0) y = -y;
    // cout << y << ' ' << x << endl;
    res.push_back({ y, x });
    mn_x = min(mn_x, x); mx_x = max(mx_x, x);
    mn_y = min(mn_y, y); mx_y = max(mx_y, y);
}

vector<string> solution(vi line) 
{
    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
            calc(line[i], line[j]);
    }
    
    ll ysz = mx_y - mn_y + 1, xsz = mx_x - mn_x + 1;
    vector<string> ans(ysz, string(xsz, '.'));
    
    for (auto to : res)
    {
        ll y = to.first - mn_y, x = to.second - mn_x;
        ans[y][x] = '*';
    }
    
    return ans;
}