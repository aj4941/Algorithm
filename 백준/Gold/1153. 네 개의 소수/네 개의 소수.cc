#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000002;
int p[N], n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) p[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (p[i] != i) continue;
        for (int j = i; j <= n; j += i)
        {
            if (p[j] == j)
                p[j] = i;
        }
    }

    if (n % 2 == 0) // even
    {
        if (n < 8)
        {
            cout << -1;
            return 0;
        }
        cout << 2 << ' ' << 2 << ' ';
        for (int i = 2; i <= n - 4; i++)
        {
            int j = (n - 4) - i;
            if (p[i] == i && p[j] == j)
            {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
    else // odd
    {
        if (n < 9)
        {
            cout << -1;
            return 0;
        }
        cout << 2 << ' ' << 3 << ' ';
        for (int i = 2; i <= n - 5; i++)
        {
            int j = (n - 5) - i;
            if (p[i] == i && p[j] == j)
            {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
}