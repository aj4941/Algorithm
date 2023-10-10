#include <bits/stdc++.h>
using namespace std;
vector<int> w, d;
int dp[10][1 << 15 + 3];
int wn, dn, n;

void solve(int i, int bit)
{
    int &ret = dp[i][bit];
    if (ret != -1) return;
    ret = 1;
    if (i == dn) return;
    
    for (int idx = 0; idx < wn; idx++)
    {
        if (bit & (1 << idx)) continue;
        int cbit = (bit | (1 << idx)), rm = d[i];
        int cidx = idx;
        while (true)
        {
            int nidx = (cidx + 1) % wn;
            int nxt_dist = (w[nidx] - w[cidx] + n) % n; 
            rm -= nxt_dist;
            if (rm >= 0) cidx = nidx, cbit |= (1 << cidx);
            else break;
        }
        solve(i + 1, cbit);
        
        cbit = (bit | (1 << idx)), rm = d[i];
        cidx = idx;
        while (true)
        {
            int nidx = (cidx - 1 + wn) % wn;
            int nxt_dist = (w[cidx] - w[nidx] + n) % n; 
            rm -= nxt_dist;
            if (rm >= 0) cidx = nidx, cbit |= (1 << cidx);
            else break;
        }
        solve(i + 1, cbit);
    }
}

int solution(int num, vector<int> weak, vector<int> dist) 
{
    n = num;
    memset(dp, -1, sizeof dp);
    w = weak, d = dist; wn = w.size(), dn = d.size();
    sort(d.rbegin(), d.rend());
    solve(0, 0);
    
    for (int i = 1; i <= dn; i++)
    {
        if (dp[i][(1 << wn) - 1] == 1)
            return i;
    }
    
    return -1;
}