#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> v) 
{
    int n = v.size();
    int l = 0, r = 1e9;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] >= mid)
                cnt++;
        }
        if (cnt >= mid) l = mid;
        else r = mid;
    }
    
    return l;
}