#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int cnt[N];

int solution(vector<int> a) 
{
    int ans = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
        a.push_back(a[i]);
    
    for (int len = 1; len <= n; len++)
    {
        int sum = 0;
        for (int k = 0; k < len; k++)
            sum += a[k];
        
        cnt[sum]++;
        if (cnt[sum] == 1) ans++;
        for (int i = len; i < a.size(); i++)
        {
            sum += a[i];
            sum -= a[i - len];
            cnt[sum]++;
            if (cnt[sum] == 1)
                ans++;
        }
    }
    
    return ans;
}