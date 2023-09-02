#include <bits/stdc++.h>
using namespace std;
int ans = 1e9;

void dfs(int n, int cnt)
{
    if (n == 0)
    {
        ans = min(ans, cnt);
        return;
    } 
    
    int r1 = 10 - (n % 10);
    if (n > 1) dfs(n / 10 + 1, cnt + r1);
    int r2 = n % 10;
    dfs(n / 10, cnt + r2);
}

int solution(int n) 
{
    dfs(n, 0);
    return ans;
}