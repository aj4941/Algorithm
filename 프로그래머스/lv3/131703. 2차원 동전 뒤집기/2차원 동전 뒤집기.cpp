#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vi;
int n, m;

int solution(vector<vector<int>> b, vector<vector<int>> t) 
{
    int ans = 1e9;
    n = b.size(), m = b[0].size();
    
    for (int bit = 0; bit < (1 << n); bit++)
    {
        vi sb = b;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                cnt++;
                for (int j = 0; j < m; j++)
                    sb[i][j] = 1 - sb[i][j];
            }
        }
        
        for (int j = 0; j < m; j++)
        {
            if (sb[0][j] == t[0][j]) continue;
            cnt++;
            for (int i = 0; i < n; i++)
                sb[i][j] = 1 - sb[i][j];
        }
        
        if (sb == t)
            ans = min(ans, cnt);
    }
    
    if (ans == 1e9)
        ans = -1;
    
    return ans;
}