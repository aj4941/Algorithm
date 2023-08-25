#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> a, int k) 
{
    int n = a.size();
    int l = 0, r = 0, sum = a[0];
    int len = 1e9, ans_l = -1, ans_r = -1;
    while (true)
    {
        if (sum == k)
        {
            if (r - l + 1 < len)
            {
                len = r - l + 1;
                ans_l = l, ans_r = r;
            }
            sum -= a[l]; l++;
        }
        else if (sum > k)
        {
            sum -= a[l]; l++;
            if (l == n) break;
            if (l > r) r = l, sum = a[l];
        }
        else
        {
            r++;
            if (r == n) break;
            sum += a[r];
        }
    }
    
    return { ans_l, ans_r };
}