#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
const int N = 10;
unordered_map<int, int> dist;
int n, m;

int cal_num(vector<int>& a)
{
    int val = 0, mul = 1;
    for (int i = (int)a.size() - 1; i >= 0; i--)
    {
        val += a[i] * mul;
        mul *= 10;
    }
    return val;
}

vector<int> cal_vec(int val)
{
    vector<int> a;
    while (a.size() < n)
    {
        a.push_back(val % 10);
        val /= 10;
    }
    reverse(a.begin(), a.end());
    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    cin >> m;
    vector<pair<pii, int>> p;
    for (int i = 0; i < m; i++)
    {
        int l, r, c; cin >> l >> r >> c;
        p.push_back({ { l - 1, r - 1 }, c });
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, cal_num(a) });

    while (!pq.empty())
    {
        auto to = pq.top(); pq.pop();
        int d = -to.first;
        int num = to.second;
        if (dist[num] != d) continue;
        vector<int> cur = cal_vec(num);
        for (int i = 0; i < m; i++)
        {
            int c = p[i].second;
            int l = p[i].first.first, r = p[i].first.second;
            swap(cur[l], cur[r]);
            int nnum = cal_num(cur);
            if (!dist.count(nnum) || d + c < dist[nnum])
            {
                dist[nnum] = d + c;
                pq.push({ -dist[nnum], nnum });
            }
            swap(cur[l], cur[r]);
        }
    }

    sort(a.begin(), a.end());
    int ans = cal_num(a);

    if (!dist.count(ans)) cout << -1;
    else cout << dist[ans];
}