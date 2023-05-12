#include <bits/stdc++.h>
using namespace std;
int ans_x = -1, ans_y = -1;

void calc(int x, int y)
{
    if (ans_x == -1)
    {
        ans_x = x, ans_y = y;
        return;
    }
    
    if (y - x < ans_y - ans_x)
        ans_x = x, ans_y = y;
}

vector<int> solution(vector<int> a, int k) 
{
    int n = a.size();
    int l = 0, r = 0, sum = a[0];
    while (true)
    {
        if (sum == k) calc(l, r);
        
        if (sum < k)
        {
            r++;
            if (r == n) break;
            sum += a[r];
        }
        else
        {
            sum -= a[l++];
            if (l > r) r = l, sum = a[r];
            if (r == n) break;
        }
        
    }
    
    return { ans_x, ans_y };
}