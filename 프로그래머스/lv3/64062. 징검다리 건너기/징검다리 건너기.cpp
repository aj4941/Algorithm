#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, int k) 
{
    int n = a.size();
    int l = 0, r = 2 * 1e8 + 3;
    while (l + 1 < r) // [l, r)
    {
        int mid = (l + r) / 2;
        int len = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] - mid <= 0) len++;
            else len = 0;
            
            if (len >= k)
                flag = false;
        }
        
        if (flag) l = mid; // 가능
        else r = mid;
    }
    
    return l + 1;
}