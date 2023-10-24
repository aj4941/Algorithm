#include <bits/stdc++.h>
using namespace std;
int num[4] = { 0, 1, 2, 4 };

string solution(int n) 
{
    vector<int> v;
    while (n > 0)
    {
        int inv = n / 3, rm = n % 3;
        if (rm == 0) inv--, rm = 3;
        v.push_back(rm);
        n = inv;
    }
    
    reverse(v.begin(), v.end());
    string ans = "";
    for (auto to : v) ans += num[to] + '0';
    
    return ans;
}