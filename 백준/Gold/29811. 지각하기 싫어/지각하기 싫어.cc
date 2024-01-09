#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };
multiset<int> a[200], b[200];
int p[300002];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a[x].insert(i + 1);
        p[i + 1] = x;
    }
    for (int i = n; i < n + m; i++)
    {
        int x; cin >> x;
        b[x].insert(i + 1);
        p[i + 1] = x;
    }

    int k; cin >> k;

    for (int i = 0; i < k; i++)
    {
        char ch; cin >> ch;
        if (ch == 'U')
        {
            int x, y; cin >> x >> y;
            int val = p[x];
            if (x <= n)
            {
                auto it = a[val].find(x);
                a[val].erase(it);
                a[y].insert(x);
                p[x] = y;
            }
            else
            {
                auto it = b[val].find(x);
                b[val].erase(it);
                b[y].insert(x);
                p[x] = y;
            }
        }
        else
        {
            // cout << "OK" << endl;
            int x = -1, y = -1;
            for (int num = 1; num <= 100; num++)
            {
                if (a[num].size())
                {
                    x = *a[num].begin();
                    break;
                }
            }
            for (int num = 1; num <= 100; num++)
            {
                if (b[num].size())
                {
                    y = *b[num].begin();
                    break;
                }
            }

            cout << x << ' ' << y << "\n";
        }
    }
}