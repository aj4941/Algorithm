#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solution(int cap, int n, vector<int> d, vector<int> p) 
{
    ll ans = 0;
    ll didx = n - 1, pidx = n - 1;
    while (didx >= 0 && d[didx] == 0) didx--;
    while (pidx >= 0 && p[pidx] == 0) pidx--;
    
    while (didx >= 0 || pidx >= 0)
    {   
        ans += (max(didx, pidx) + 1) * 2;
        ll a = 0, b = 0;
        
        while (didx >= 0)
        {
            int ra = cap - a;
            int ma = min(d[didx], ra);
            a += ma, d[didx] -= ma;
            if (d[didx] == 0) didx--;
            else break;
        }
        
        while (pidx >= 0)
        {
            int rb = cap - b;
            int mb = min(p[pidx], rb);
            b += mb, p[pidx] -= mb;
            if (p[pidx] == 0) pidx--;
            else break;
        }
    }
    
    return ans;
}