#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<pii> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, h; cin >> n >> m >> h;
    pii st = { -1, -1 };
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        int c; cin >> c;
        if (c == 1) st.first = i, st.second = j;
        else if (c == 2) v.push_back({ i, j });
    }

    vector<int> p;
    for (int i = 0; i < v.size(); i++) p.push_back(i);

    int ans = 0;

    do {
        int cm = m, cnt = 0;
        pii pos = st;
        for (int i = 0; i < v.size(); i++)
        {
            int d = abs(v[p[i]].first - pos.first) + abs(v[p[i]].second - pos.second);
            if (d <= cm)
            {
                cm -= d; cm += h;
                pos = v[p[i]]; cnt++;
                if (abs(pos.first - st.first) + abs(pos.second - st.second) <= cm)
                    ans = max(ans, cnt);
            }
            else
                break;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans;
}