#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;

ll solution(int n, int m, int x, int y, vi q) 
{
    ll ans = 0;
    int x1 = x, y1 = y, x2 = x, y2 = y;
    reverse(q.begin(), q.end());
    
    for (auto to : q)
    {
        int cmd = to[0], dx = to[1];
        
        if (cmd == 0)
        {
            if (y1 > 0) y1 = y1 + dx;
            y2 = min(m - 1, y2 + dx);
        }
        else if (cmd == 1)
        {
            y1 = max(0, y1 - dx);
            if (y2 < m - 1) y2 = y2 - dx;
        }
        else if (cmd == 2)
        {
            if (x1 > 0) x1 = x1 + dx;
            x2 = min(n - 1, x2 + dx);
        }
        else // cmd == 3
        {
            x1 = max(0, x1 - dx);
            if (x2 < n - 1) x2 = x2 - dx;
        }
        
        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        if (x1 >= n || x2 < 0 || y1 >= m || y2 < 0)
            return 0;
    }
    
    return (ll)(x2 - x1 + 1) * (ll)(y2 - y1 + 1);
}