#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, 0, 0, 0 };
int dy[4] = { 0, 1, 1, -1 };
int ans = -1e9, ans_idx = -1;
int turn;

void dfs(int idx, int cnt, vector<int> &v, vector<int> &tmp)
{
    if (cnt == 3)
    {
        int res = (tmp[0] + tmp[1] + tmp[2]) % 10;
        if (ans <= res)
        {
            ans = res;
            ans_idx = turn;
        }
        return;
    }

    for (int i = idx; i < 5; i++)
    {
        tmp.push_back(v[i]);
        dfs(i + 1, cnt + 1, v, tmp);
        tmp.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        vector<int> v, tmp;
        for (int j = 0; j < 5; j++)
        {
            int x; cin >> x;
            v.push_back(x);
        }
        turn = i;
        dfs(0, 0, v, tmp);
    }

    cout << ans_idx;
}