#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    
    return gcd(y, x % y);
}

int solution(vector<int> a, vector<int> b)
{
    int ga = 0, gb = 0;
    for (auto to : a) ga = gcd(ga, to);
    for (auto to : b) gb = gcd(gb, to);
    // cout << ga << ' ' << gb << endl;
    int ans = 0;
    bool flagA = true, flagB = true;
    for (auto to : a)
    {
        if (to % gb == 0)
            flagA = false;
    }
    for (auto to : b)
    {
        if (to % ga == 0)
            flagB = false;
    }
    if (flagA) ans = max(ans, gb);
    if (flagB) ans = max(ans, ga);
    
    return ans;
}