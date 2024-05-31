#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int a[502][2502], tmp[502][2502];
int b, c;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    while (true)
    {
        cin >> b >> c;
        if (b == 0 && c == 0) break;
        for (int i = 0; i < b; i++) for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            tmp[i][a[i][j]] = j;
        }

        queue<int> q;
        for (int i = 0; i < c; i++) q.push(i);
        while (q.size() > 1)
        {
            int xw = 0, yw = 0;
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();
            for (int i = 0; i < b; i++)
            {
                if (tmp[i][x] < tmp[i][y]) xw++;
                else yw++;
            }

            if (xw < yw) q.push(y);
            else q.push(x);
        }

        int ans = q.front();
        vector<ll> p(c + 1);

        for (int i = 0; i < b; i++)
        {
            bool flag = false;
            for (int j = 0; j < c; j++)
            {
                if (ans == a[i][j])
                {
                    flag = true;
                    continue;
                }

                if (flag) p[a[i][j]]++;
                else p[a[i][j]]--;
            }
        }

        for (int j = 0; j < c; j++)
        {
            if (j == ans) continue;
            if (p[j] <= 0)
            {
                ans = -1;
                break;
            }
        }

        cout << "Case " << tc++ << ": ";
        if (ans == -1)
            cout << "No Condorcet winner" << "\n";
        else
            cout << ans << "\n";
    }
}