#include <bits/stdc++.h>
using namespace std;

bool calc(int a, int b)
{
    int acnt = 0, bcnt = 0;
    while (a > 0) 
    {
        acnt += a % 2;
        a /= 2;
    }
    while (b > 0)
    {
        bcnt += b % 2;
        b /= 2;
    }
    return (acnt == bcnt);
}

int solution(int n) 
{
    int ans = n + 1;
    while (true)
    {
        if (calc(ans, n))
            break;
        ans++;
    }
    
    return ans;
}