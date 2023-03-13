#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> v, int w)
{
    int st = 1, idx = 0, ans = 0;
    while (st <= n)
    {
        if (idx < v.size() && v[idx] - w <= st && st <= v[idx] + w)
        {
            st = v[idx] + w + 1;
            idx++;
        }
        else
        {
            st += 2 * w + 1;
            ans++;
        }    
    }
    return ans;
}