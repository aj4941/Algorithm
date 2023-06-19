#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
#define INF 1000000007
int board[1002][1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> m >> n;
    int cnt = 0;
    queue<pii> q1, q2;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        cin >> board[i][j];
        if (board[i][j] == 1)
        {
            q1.push({ i, j });
        }
        else if (board[i][j] == 0) 
            cnt++;
    }
    bool hasAns = false; 
    int ans = 0;
    while (true)
    {
        if (cnt == 0)
        {
            hasAns = true;
            break;
        }
        while (!q1.empty())
        {
            pii v = q1.front(); q1.pop();
            int x = v.first, y = v.second;
            for (int i = 0; i < 4; i++)
            {
                int cx = x + dx[i], cy = y + dy[i];
                if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                if (board[cx][cy] == 0)
                {
                    q2.push({ cx, cy });
                    cnt--; board[cx][cy] = 1;
                }
            }
        }
        if (q2.empty()) break;
        while (!q2.empty())
        {
            pii v = q2.front(); q2.pop();
            q1.push(v);
        }
        ans++;
    }
    if (hasAns) cout << ans;
    else cout << -1;
}