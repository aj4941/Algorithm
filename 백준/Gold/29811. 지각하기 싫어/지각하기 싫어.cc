#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };
const int N = 200002;
priority_queue<pii> a, b;
int p[N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push({ -x, -(i + 1) });
        p[i + 1] = x;
    }
    for (int i = n; i < n + m; i++)
    {
        int x; cin >> x;
        b.push({ -x, -(i + 1) });
        p[i + 1] = x;
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++)
    {
        char c; cin >> c;
        if (c == 'U')
        {
            int x, y; cin >> x >> y;
            p[x] = y;
            if (x <= n) a.push({ -y, -x });
            else b.push({ -y, -x });
        }
        else
        {
            int resA = -1, resB = -1;
            while (a.size())
            {
                auto to = a.top();
                int x = -to.second, y = -to.first;
                if (p[x] == y)
                {
                    resA = x;
                    break;
                }
                a.pop();
            }

            while (b.size())
            {
                auto to = b.top();
                int x = -to.second, y = -to.first;
                if (p[x] == y)
                {
                    resB = x;
                    break;
                }
                b.pop();
            }

            cout << resA << ' ' << resB << "\n";
        }
    }
}
