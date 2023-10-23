#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(int n, vector<int> c) 
{   
    if (n <= c.size())
        return n;
    
    ll l = 0, r = 3 * 1e8;
    
    while (l + 1 < r) // (l, r]
    {
        ll mid = (l + r) / 2, cnt = 0;
        for (auto to : c)
            cnt += (mid / to) + 1;
        
        if (cnt >= n) r = mid;
        else l = mid;
    }
    
    ll rm = n;
    
    for (int i = 0; i < c.size(); i++)
        rm -= ((r - 1) / c[i] + 1);
    
    for (int i = 0; i < c.size(); i++)
    {
        if (r % c[i] == 0) rm--;
        if (rm == 0)
            return i + 1;
    }
}