#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solution(vector<int> v) 
{
    int n = v.size();
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            v1.push_back(v[i]);
            v2.push_back(-v[i]);
        }
        else
        {
            v1.push_back(-v[i]);
            v2.push_back(v[i]);
        }
    }
    
    ll sum1 = 0, sum2 = 0;
    ll ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum1 += v1[i], sum2 += v2[i];
        if (sum1 < 0) sum1 = 0;
        if (sum2 < 0) sum2 = 0;
        ans = max(ans, max(sum1, sum2));
    }
    
    return ans;
}