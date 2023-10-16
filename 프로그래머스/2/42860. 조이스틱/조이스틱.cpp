#include <bits/stdc++.h>
using namespace std;
int prv[25];
int n;
int mn = 1e9;

void dfs(int idx, deque<int>& dq)
{
    if (idx == dq.size())
    {
        int cur = 0, res = 0;
        deque<int> sdq = dq;
        for (int i = 0; i < dq.size(); i++)
        {
            if (prv[i] == 0)
            {
                res += (cur - sdq.back() + n) % n;
                cur = sdq.back(); sdq.pop_back();
            }
            else
            {
                res += (sdq.front() - cur + n) % n;
                cur = sdq.front(); sdq.pop_front();
            }
        }
        
        mn = min(mn, res);
        return;
    }
    
    for (int i = 0; i < 2; i++)
    {
        prv[idx] = i;
        dfs(idx + 1, dq);
    }
}

int solution(string s) 
{
    n = s.size();
    int ans = 0;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'A')
        {
            if (i > 0) dq.push_back(i);
            int r1 = (s[i] - 'A');
            int r2 = ('A' - s[i] + 26) % 26;
            ans += min(r1, r2);
        }
    }
    
    dfs(0, dq);
    return ans + mn;
}