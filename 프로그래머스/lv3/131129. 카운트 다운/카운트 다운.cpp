#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 100002;
pii dp[N];
int val[4] = { 1, 2, 3, 50 };

bool calc(pii &a, pii &b) // a < b ?
{
    if (a.first != b.first)
        return a.first > b.first;
    
    return a.second < b.second;
}

pii solve(int v)
{
    pii &ret = dp[v];
    if (ret.first != -1) return ret;
    ret = pii(1e9, -1e9);
    if (v == 0) return ret = pii(0, 0);
    
    for (int c = 0; c < 4; c++)
    {
        for (int p = 1; p <= 20; p++) 
        {
            int value = (c != 3) ? val[c] * p : 50;
            if (v - value >= 0)
            {
                pii res = solve(v - value);
                res.first++;
                if (c == 0 || c == 3) res.second++;
                if (calc(ret, res))
                    ret = res;
            }
        }
    }
    
    return ret;
}

vector<int> solution(int t) 
{   
    for (int i = 0; i < N; i++)
        dp[i] = pii(-1, -1);
    
    pii res = solve(t);
    
    return { res.first, res.second };
}