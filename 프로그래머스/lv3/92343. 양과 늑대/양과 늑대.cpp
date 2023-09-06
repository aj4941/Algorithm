#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
const int N = 17;
vector<int> g[N];
bool dp[1 << N]; // 0 ~ 16

int solution(vector<int> info, vi edges)
{
    int n = info.size();
    
    for (auto to : edges)
    {
        int u = to[0], v = to[1];
        g[u].push_back(v); g[v].push_back(u);
    }
    
    dp[1] = true;
    
    for (int bit = 1; bit < (1 << n); bit++) // 2^17
    {
        if (!dp[bit]) continue;
        int s = 0, w = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                if (info[i] == 0) s++;
                else w++;
            }
        }
        
        for (int x = 0; x < n; x++) // 17
        {
            if (bit & (1 << x))
            {
                for (int nx : g[x])
                {
                    if (bit & (1 << nx)) continue;
                    if (info[nx] == 0) dp[bit | (1 << nx)] = true;
                    else if (s > w + 1) dp[bit | (1 << nx)] = true;
                }
            }
        }
    }
    
    int ans = 0;
    
    for (int bit = 0; bit < (1 << n); bit++)
    {
        if (!dp[bit]) continue;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                if (info[i] == 0)
                    cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    
    return ans;
}