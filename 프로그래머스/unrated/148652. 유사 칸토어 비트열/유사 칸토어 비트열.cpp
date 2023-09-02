#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, ll x)
{
    if (x % 5 == 2) return 0;
    x /= 5, n--;
    if (n < 0) return 1;
    else return solve(n, x);
}

int solution(int n, ll l, ll r) 
{
    int ans = 0;
    for (ll x = l - 1; x <= r - 1; x++)
        ans += solve(n, x);
    
    return ans;
}